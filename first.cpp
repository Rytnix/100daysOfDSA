#include <bits/stdc++.h>
using namespace std;


template <typename T>
void print(const T& a){
   cout<<a<<" ";
}

void printline(){
    cout<<endl;
}
/*
 
 PATTERN 1:

* * * * * 
* * * * * 
* * * * * 
* * * * * 
* * * * * 

*/

void pattern_one(int size){

  for(int i=0;i<size;i++){
    for(int j=0;j<size;j++){
       print('*');
    }
    printline();
  }

}

/*
  PATTERN 2:

* 
* * 
* * * 
* * * * 
* * * * * 

*/

void pattern_two(int size){

  for(int i=0;i<size;i++){
    for(int j=0;j<=i;j++){
       print('*');
    }
    printline();
  }

}

/*
 PATTERN 3:

1 
1 2 
1 2 3 
1 2 3 4 
1 2 3 4 5 

*/

void pattern_three(int size){

  for(int i=1;i<=size;i++){
    for(int j=1;j<=i;j++){
       print(j);
    }
    printline();
  }

}

/*
  PATTERN 4: 

1 
2 2 
3 3 3 
4 4 4 4 
5 5 5 5 5 

*/

void pattern_four(int size){

  for(int i=1;i<=size;i++){
    for(int j=1;j<=i;j++){
       print(i);
    }
    printline();
  }

}

/*
  PATTERN 5:

* * * * * 
* * * *   
* * *     
* *       
*  

*/

void pattern_five(int size){

  for(int i = 0;i<size;i++){
    for(int j=0;j<size;j++){

      if(j<size-i){
        print('*');
      }
      else{
        print(' ');
      }
    }
    printline();
  }
}

/*
  PATTERN 6:

1 2 3 4 5 
1 2 3 4   
1 2 3     
1 2       
1   

*/

void pattern_six(int size){

  for(int i = 1;i<=size;i++){
    for(int j=1;j<=size;j++){

      if(j<=size+1-i){
        print(j);
      }
      else{
        print(' ');
      }
    }
    printline();
  }
}


/*
  PATTERN 7:

        *         
      * * *       
    * * * * *     
  * * * * * * *   
* * * * * * * * * 

*/

void pattern_seven(int size){

  for(int i=0;i<size;i++){
    for(int j=1;j<(size*2);j++){
      if(j>=(size-i) && j<=(size+i)){
         print('*');
      }
      else{
        // cout<<"sp";
        print(' ');
      }
    }
   printline();
  }

}

/*
  PATTERN 8:

* * * * * * * * * 
  * * * * * * *   
    * * * * *     
      * * *       
        *  
        
*/
void pattern_eight(int size){

  for(int i=0;i<size;i++){
    for(int j=0;j<(size*2)-1;j++){
      if(j>=i && j<(size*2-1)-i ){
         print('*');
      }
      else{
        // cout<<"sp";
        print(' ');
      }
    }
   printline();
  }

}

/* 
  PATTERN 9:

        *         
      * * *       
    * * * * *     
  * * * * * * *   
* * * * * * * * * 
* * * * * * * * * 
  * * * * * * *   
    * * * * *     
      * * *       
        *         
*/

void pattern_nine(int size){
   pattern_seven(size);
   pattern_eight(size);
}


/*
 PATTERN 10:

*         
* *       
* * *     
* * * *   
* * * * * 
* * * *   
* * *     
* *       
*

*/

void pattern_ten(int size){

  for(int i =0;i<size*2-1;i++){
    for(int j=0;j<size;j++){
      if(i<size && j<=i )
        print("*");
      else if(i>=size && j<(2*size - i - 1) )
        print("*");
      else
        print(" ");
        
    }
    printline();
  }
}

/* 
* PATTERN 11:

1         
0 1       
1 0 1     
0 1 0 1   
1 0 1 0 1 

*/

void pattern_eleven(int size){
  bool inverter = false;
   for(int i=1;i<=size;i++){
        if((i%2)!=0)
            inverter = inverter?false:true;
    for(int j=1;j<=size;j++){
      if(j<=i){
        print((inverter));
        inverter = inverter?false:true;
      }
      else
         print( " ");
    }
    printline();
  }
}

/*
 PATTERN 12:

1                 1 
1 2             2 1 
1 2 3         3 2 1 
1 2 3 4     4 3 2 1 
1 2 3 4 5 5 4 3 2 1

*/

void pattern_twelve(int size){

  for(int i =1;i<=size;i++){
    int descValue=i;
    for(int j=1;j<=size*2;j++){
      if(j<=i) 
        print(j);
      else if(j>(size*2)-i) {
        print(descValue);
        descValue--;
      }
      else
        print(" ");
        
    }
    printline();
  }
}


/* 
 PATTERN 13:

1     
2 3    
4 5 6   
7 8 9 10  
11 12 13 14 15

*/

void pattern_thirteen(int size){

  for(int i=1,k=i;i<=size;i++){
    for(int j=1;j<=size;j++){
      if(j<=i){
        print(k);
        k++;
      } 
      else 
       print(" ");
      
    }
    printline();
  }
}

/* 
 PATTERN 14:

A     
A B    
A B C   
A B C D  
A B C D E 

*/

void pattern_fourteen(int size){

  for(int i=1,k=i;i<=size;i++){
    char a = 65;
    for(int j=1;j<=size;j++){
      if(j<=i){
        print(a);
        a++;
      } 
      else 
       print(" ");
      
    }
    printline();
  }
}

/* 
 PATTERN 15:

A B C D E 
A B C D  
A B C   
A B    
A  

*/

void pattern_fifteen(int size){

  for(int i=1,k=i;i<=size;i++){
    char a = 65;
    for(int j=1;j<=size;j++){
      if(j<=size-i+1){
        print(a);
        a++;
      } 
      else 
       print(" ");
      
    }
    printline();
  }
}

/* 
 PATTERN 16:

A         
B B       
C C C     
D D D D   
E E E E E  

*/

void pattern_sixteen(int size){

  char a = 65;
  for(int i=1;i<=size;i++){
    for(int j=1;j<=size;j++){
      if(j<=i)
        print(a);
      else 
       print(" ");
      
    }
    a++;
    printline();
  }
}

/* 
 PATTERN 17:

        A         
      A B A       
    A B C B A     
  A B C D C B A   
A B C D E D C B A 

*/

void pattern_seventeen(int size){

  for(int i=1;i<=size;i++){
    char a = 64;
    for(int j=1;j<=(size*2)-1;j++){
      if(j>=(size-i+1) && j<=(size+i-1)){
        if(j>size){
          a--;
          print(a);
        }
        else{
          a++;
          print(a);
        }
      }
      else 
       print(" ");
      
    }
    printline();
  }
}

/* 
* PATTERN 18:

E         
D E       
C D E     
B C D E   
A B C D E 

*/

void pattern_eighteen(int size){
  for(int i=0;i<size;i++){
  char dynamicChar = 'A' + (size-1) - i;
    for(int j = 0;j<size;j++){
      if(j<=i){
        print(dynamicChar);
        dynamicChar++;
      }
      else
         print(" ");
    }
    printline();
  }
}

/* 
* PATTERN 19:

* * * * * * * * * * 
* * * *     * * * * 
* * *         * * * 
* *             * * 
*                 * 
1                 1 
1 2             2 1 
1 2 3         3 2 1 
1 2 3 4     4 3 2 1 
1 2 3 4 5 5 4 3 2 1 

*/

void pattern_nineteen(int size){
  for(int i=0;i<size;i++){
    for(int j=0;j<size*2;j++){
      if(j<=size-i-1 || j>=size+i ){
        print("*");
      }
      else
         print(" ");
    }
    printline();
  }
  pattern_twelve(size);
}

/* 
* PATTERN 20:

*                 * 
* *             * * 
* * *         * * * 
* * * *     * * * * 
* * * * * * * * * * 
* * * *     * * * * 
* * *         * * * 
* *             * * 
*                 * 

*/

void pattern_twenty(int size){
  for(int i=0;i<size*2-1;i++){
    for(int j = 0;j<size*2;j++){
      if(i<size){
      if(j<=i || j>=(size*2)-i-1){
        print("*");
      }
      else
         print(" ");
    } else{
        if(j<(2*size)-i-1 || j>=i+1){
          print("*");
      }
        else
         print(" ");
      }
    }
    printline();
  }
}

/* 
* PATTERN 21:

* * * * *

*       *

*       *

*       *

* * * * *

*/

void pattern_twentyOne(int size){
  for(int i=1;i<=(size*2)-1;i++){
    for(int j = 1;j<=size;j++){
        
      if(i==1 || i==(size*2)-1){
        print("*");
        }
      else if((i&1)){
        if(j==1 || j==size){
          print("*");
        }   
        else{
          print(" ");
        }
      }
      else{
        print(" ");
      }
    }
    printline();
  }
}

/* 
* PATTERN 22:


5 5 5 5 5 5 5 5 5 
5 4 4 4 4 4 4 4 5 
5 4 3 3 3 3 3 4 5 
5 4 3 2 2 2 3 4 5 
5 4 3 2 1 2 3 4 5 
5 4 3 2 2 2 3 4 5 
5 4 3 3 3 3 3 4 5 
5 4 4 4 4 4 4 4 5 
5 5 5 5 5 5 5 5 5 

*/

void pattern_twentyTwo(int size){
  for(int i=1;i<=size*2-1;i++){
    int middle = i<=size?size-i+1:i-size+1;
    int outer = size; 
    for(int j = 1;j<=size*2-1;j++){
      if(i<=size){
        if(j>=i && j<=(size*2)-i){
          print(middle);
        }
        else if(j<=i){
          print(outer);
          outer= outer - 1;
        }
        else if(j>=(size*2)-i){
          outer = outer+1;
          print(outer);
        }
      }
      else{
       if(j>=(size*2)-i && j<=i)  
          print(middle);
       else if(j<(size*2-i)){
          print(outer);
          outer= outer - 1;
        }
       else if(j>i){
          outer = outer+1;
          print(outer);
        }
        
      }
    }
    printline();
  }
}



int main(){
  int size = 9;
  pattern_one(size);
  printline();
  pattern_two(size);
  printline();
  pattern_three(size);
  printline();
  pattern_four(size);
  printline();
  pattern_five(size);
  printline();
  pattern_six(size);
  printline();
  pattern_seven(size);
  printline();
  pattern_eight(size);
  printline();
  pattern_nine(size);
  printline();
  pattern_ten(size);
  printline();
  pattern_eleven(size);
  printline();
  pattern_twelve(size);
  printline();
  pattern_thirteen(size);
  printline();
  pattern_fourteen(size);
  printline();
  pattern_fifteen(size);
  printline();
  pattern_sixteen(size);
  printline();
  pattern_seventeen(size);
  printline();
  pattern_eighteen(size);
  printline();
  pattern_nineteen(size);
  printline();
  pattern_twenty(size);
  printline();
  pattern_twentyOne(size);
  printline();
  pattern_twentyTwo(size);

}
