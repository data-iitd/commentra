
#include<iostream>

int main(void){
   int N, D; /* N, Dは1以上20以下の integers */
   int ans, rem;

   std::cin >> N >> D;

   ans = N / (D*2+1);
   rem = N % (D*2+1);

   if(rem!= 0){
       ans = ans + 1;
   }
  
   std::cout << ans << std::endl;


	return 0;
}

