#include<stdio.h>
#include<stdlib.h>
#include<math.h>

// Define a type for 64-bit integers
typedef long long int int64;

// Macros for mathematical operations: MAX, MIN, and ABS
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

// Function to count the number of digits in a given integer
int digit(int64 n){
  int res=0; // Initialize digit count to zero
  // Loop until all digits are processed
  while(n>0){
    res++; // Increment digit count
    n/=10; // Remove the last digit
  }
  return res; // Return the total count of digits
}

// Function to execute the main logic of the program
void run(void){
  int64 n; // Variable to store the input number
  // Read a long long integer from standard input
  scanf("%lld",&n);
  
  // Initialize minimum digit count with the digit count of n
  int min=digit(n);
  int i;

  // Loop through all possible divisors of n
  for(i=1;(int64)i*i<=n;i++){
    // Skip if i is not a divisor of n
    if(n%i!=0) continue;
    
    // Calculate the corresponding divisor
    int64 a=i;
    int64 b=n/i;

    // Update the minimum digit count based on the digits of the divisors
    min=MIN(min,MAX(digit(a),digit(b)));
  }
  
  // Print the minimum digit count found
  printf("%d\n",min);
}

// Main function to start the program execution
int main(void){
  run(); // Call the run function to execute the logic
  return 0; // Return success
}

