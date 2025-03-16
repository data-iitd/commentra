#include<iostream>

using namespace std;

int main(void){
   int N, D; /* N, Dは1以上20以下の整数 */
   int ans, rem;

   cin >> N >> D;

   ans = N / (D*2+1);
   rem = N % (D*2+1);

   if(rem!= 0){
       ans = ans + 1;
   }
  
   cout << ans << endl;


	return 0;
}

