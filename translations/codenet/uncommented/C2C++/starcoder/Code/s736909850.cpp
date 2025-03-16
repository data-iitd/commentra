#include<iostream>

using namespace std;

int main(void){
   int sheep;
   int wolf;

   cin>>sheep>>wolf;

   if(wolf>=sheep){
      cout<<"unsafe\n";
   } else {
      cout<<"safe\n";
   }

   return 0;
}
