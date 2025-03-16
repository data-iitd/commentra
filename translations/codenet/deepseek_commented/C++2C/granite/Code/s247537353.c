
#include <stdio.h>

int main(){
  // Fast I/O setup
  setbuf(stdout, NULL);

  // Declare variables to store input values
  long long A,B,C,K;
  scanf("%lld %lld %lld %lld",&A,&B,&C,&K);

  // Check if the sum of A and B is greater than or equal to K
  if(A+B>=K){
    // Output the minimum of A and K
    printf("%lld\n",A<K?A:K);
  }else{
    // Calculate the result by subtracting the excess amount from A
    printf("%lld\n",A-(K-(A+B)));
  }
}

// 