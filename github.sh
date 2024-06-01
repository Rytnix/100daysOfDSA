
#!/bin/bash

# Function to add a new GitHub account
add_github_account() {
  gh auth login
  if [ $? -ne 0 ]; then
    echo "Failed to add account. Exiting."
    exit 1
  fi
  echo "Account added successfully."
}

# Function to list GitHub accounts
list_github_accounts() {
  echo "Available GitHub accounts:"
  gh auth status --show-token 2>&1 | grep "Logged in to" | awk '{print NR") " $7}'
}

# Function to authenticate to GitHub
authenticate_github() {
  list_github_accounts

  read -p "Select an account by number: " account_number
  selected_account=$(gh auth status --show-token 2>&1 | grep "Logged in to" | awk "NR==$account_number{print \$7}")
    selected_account_token=$(gh auth status --show-token 2>&1 | awk -v account_number=$account_number '
/Logged in to github.com account/ {account_line++; if (account_line == account_number) account=$7}
account_line == account_number && /Token:/ {print $3; exit}')  

  if [ -z "$selected_account" ]; then
    echo "Invalid selection. Exiting."
    exit 1
  fi

  echo "Switching to account: $selected_account"
  gh auth login --with-token <<< $selected_account_token
}

# Function to select user configuration
select_user_config() {
  read -p "Enter your name: " user_name
  read -p "Enter your email: " user_email

  git config --global user.name "$user_name"
  git config --global user.email "$user_email"
}

# Function to initialize Git repository if not present
initialize_git_repo() {
  if [ ! -d .git ]; then
    echo "Initializing new Git repository..."
    git init
    git branch -M SayNoToMaster

    echo "Fetching remote repository URL..."
    repo_url=$(gh repo view "$repo_name" --json url -q .url)
    git remote add origin "$repo_url"
    git fetch origin
  fi
}

# Function to list repositories
list_repositories() {
  gh repo list --json name --jq '.[].name'
}

# Function to search repositories in real-time using fzf
search_repositories() {
  repos=$(list_repositories)
  if [ -z "$repos" ]; then
    echo "No repositories found."
    exit 1
  fi

  echo "Select a repository:"
  selected_repo=$(echo "$repos" | fzf --height 40% --border --preview "gh repo view {}")

  if [ -z "$selected_repo" ]; then
    echo "No repository selected."
    exit 1
  fi

  echo "Selected repository: $selected_repo"
  repo_name="$selected_repo"
}

# Function to commit and push changes to GitHub
commit_and_push() {
  echo "Checking if the repository '$repo_name' exists..."
  if gh repo view "$repo_name" > /dev/null 2>&1; then
    echo "Repository found."

    initialize_git_repo

    git add .
    read -p "Enter commit message: " commit_message
    git commit -m "$commit_message"
    git push origin SayNoToMaster

    echo "Changes pushed to GitHub."
  else
    echo "Repository not found."
    exit 1
  fi
}

# Function to create a new repository on GitHub
create_new_repo() {
  read -p "Enter the name for the new repository: " new_repo_name
  gh repo create "$new_repo_name" --public --confirm
  if [ $? -ne 0 ]; then
    echo "Failed to create the repository. Exiting."
    exit 1
  fi
  echo "Repository '$new_repo_name' created successfully."
  repo_name="$new_repo_name"
}

# Main script execution
read -p "Do you want to add a new GitHub account? (y/n): " add_account
if [ "$add_account" == "y" ]; then
  add_github_account
fi

authenticate_github

read -p "Do you want to create a new repository or use an existing one? (create/use): " repo_choice
if [ "$repo_choice" == "create" ]; then
  create_new_repo
else
  search_repositories
  commit_and_push
fi

