#include<stdio.h>
#include<stdlib.h>
#include<math.h>

// Define a type alias for long long int
typedef long long int int64;

// Define macros for maximum, minimum, and absolute value
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

// Function to count the number of digits in a number
int digit(int64 n){
  int res=0;
  while(n>0){
    res++;
    n/=10;
  }
  return res;
}

// Main logic of the program
void run(void){
  int64 n;
  scanf("%lld",&n);
  int min=digit(n);
  int i;
  for(i=1;(int64)i*i<=n;i++){
    if(n%i!=0) continue;
    int64 a=i;
    int64 b=n/i;
    min=MIN(min,MAX(digit(a),digit(b)));
  }
  printf("%d\n",min);
}

// Main function
int main(void){
  run();
  return 0;
}