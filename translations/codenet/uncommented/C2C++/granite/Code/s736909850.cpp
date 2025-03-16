
#include<iostream>

int main(void){
   int sheep;
   int wolf;

   std::cin>>sheep>>wolf;

   if(wolf>=sheep){
      std::cout<<"unsafe\n";
   } else {
      std::cout<<"safe\n";
   }

   return 0;
}
