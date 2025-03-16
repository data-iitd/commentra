#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
 

 
def main():
    X,A,B,C=0,0,0,0
    i=0
    j=0
    k=0
    kosu=0
  
 # 整数の入力
    X=int(input())
    A=int(input())
    B=int(input())
    C=int(input())
    X=X/50;
  
   for i in range(A+1):
     for j in range(B+1):
       for k in range(C+1):
         if(X==(10*i)+(2*j)+k) kosu+=1
  
     

  print(kosu)

