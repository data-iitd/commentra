#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <limits.h>
#include <float.h>
#include <time.h>
#include <ctype.h>
#include <assert.h>

// Chmin and chmax are helper functions to update a variable with the minimum or maximum of it and another value, respectively.
bool chmin(int *a, int b) {
  if (*a > b) { // if the current value is greater than the new value
    *a = b; // update the current value with the new value
    return true; // return true to indicate an update occurred
  }
  return false; // otherwise, return false
}
bool chmax(int *a, int b) {
  if (*a < b) { // if the current value is less than the new value
    *a = b; // update the current value with the new value
    return true; // return true to indicate an update occurred
  }
  return false; // otherwise, return false
}

const int INF = (1 << 30) - 1; // constant definition for a large integer value
const long long INFLL= (1LL << 61) - 1; // constant definition for a large long long integer value
const int MOD = 1000000007; // constant definition for the modulus value
#define ALL(a) (a).begin(),(a).end() // macro definition for getting the iterator range of a container
#define rALL(a) (a).rbegin(),(a).rend() // macro definition for getting the reverse iterator range of a container
#define FOR(i,a,b) for(int i=(a);i<(b);++i) // for loop definition with initialization, condition, and increment
#define REP(i,n) FOR(i,0,n) // repetition loop definition with loop variable and loop count

int main(){
  // Read input values from the standard input
  scanf("%d %d %d %d",&A,&B,&C,&K);

  // Check if the sum of A and B is greater than or equal to K
  if(A+B>=K){
    // If true, print the minimum value between A and K
    printf("%d\n",min(A,K));
  }else{
    // If false, calculate the difference between K and the sum of A and B,
    // and subtract it from A to get the required value
    printf("%d\n",A-(K-(A+B)));
  }
}

