#include<iostream>

using namespace std;

int main(void){
   int sheep;
   int wolf;

   cin >> sheep >> wolf;

   if(wolf>=sheep){
      cout << "unsafe" << endl;
   } else {
      cout << "safe" << endl;
   }

   return 0;
}

