
#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
 

 
int main()
{
    int X,A,B,C;
    int i=0;
    int j=0;
    int k=0;
    int kosu=0;
  
 // 整数の入力
    scanf("%d", &A);
    scanf("%d", &B);
    scanf("%d", &C);
    scanf("%d", &X);
  
  X=X/50;
  
   for i in range(0,A+1):
     for j in range(0,B+1):
       for k in range(0,C+1):
         if X == (10*i)+(2*j)+k:
           kosu += 1
  
 
     

  print kosu

return 0;
}
