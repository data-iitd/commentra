
#include<iostream>
#include <string>
#include <math.h>
 

 
int main()
{
    int X,A,B,C;
    int i=0;
    int j=0;
    int k=0;
    int kosu=0;
  
 // 整数の入力
    std::cin >> A;
    std::cin >> B;
    std::cin >> C;
    std::cin >> X;
  
  X=X/50;
  
   for(i=0;i<=A;i++){
     for(j=0;j<=B;j++){
       for(k=0;k<=C;k++){
         if(X==(10*i)+(2*j)+k) kosu++;
       }
     }
   }
  
     

  std::cout <<kosu << std::endl;

return 0;
}
