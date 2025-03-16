#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>

// Function to check and update the minimum value of a variable
bool chmin(int *a, int b) {
  if (*a > b) {
    *a = b;
    return true;
  }
  return false;
}

// Function to check and update the maximum value of a variable
bool chmax(int *a, int b) {
  if (*a < b) {
    *a = b;
    return true;
  }
  return false;
}

// Define constants for maximum values
const int INF = (1 << 30) - 1;
const long long INFLL= (1LL << 61) - 1;
const int MOD = 1000000007;

// Macro to iterate over all elements in a container
#define ALL(a) (a).begin(),(a).end()
#define rALL(a) (a).rbegin(),(a).rend()
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)

int main(){
  // Fast I/O setup
  setvbuf(stdin, NULL, _IONBF, 0);
  setvbuf(stdout, NULL, _IONBF, 0);

  // Declare variables to store input values
  long long A,B,C,K;
  scanf("%lld %lld %lld %lld",&A,&B,&C,&K);

  // Check if the sum of A and B is greater than or equal to K
  if(A+B>=K){
    // Output the minimum of A and K
    printf("%lld\n",min(A,K));
  }else{
    // Calculate the result by subtracting the excess amount from A
    printf("%lld\n",A-(K-(A+B)));
  }
}

