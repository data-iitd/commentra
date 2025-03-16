#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

// Function to find the greatest common divisor (GCD) of two numbers
int gcd(int x, int y) {
  // Base case: if x is smaller than y, swap x and y
  if (x < y){
    int temp = x;
    x = y;
    y = temp;
  }

  // Recursive case: find the remainder of x divided by y and repeat
  while (y > 0) {
    int r = x % y;
    x = y;
    y = r;
  }

  // Return the GCD (the last non-zero value of x)
  return x;
}

// Function to find the least common multiple (LCM) of two numbers
int lcm(int x,int y){
  // Return the product of x and y divided by their GCD
  return x/gcd(x,y)*y;
}

// Function to calculate the factorial (kaijo) of a number
int kaijo(int k){
    int sum = 1;
    // Calculate the factorial by multiplying the number with all the numbers less than it
    for (int i = 1; i <= k; ++i)
    {
        sum *= i;
        // Modulo the result by 1000000000+7 to keep the result within a certain range
        sum%=1000000000+7;
    }
    // Return the result
    return sum;
}

// Macro to simplify for loops
#define FOR(i, a, b) for(int i = a; i < b; i++)

// Function to find the larger of two numbers
int lmax(int s,int t){
  // Return the larger of the two numbers
  if(s>t){
    return s;
  }
  else{
    return t;
  }
}

// Function to find the smaller of two numbers
int lmin(int s,int t){
  // Return the smaller of the two numbers
  if(s<t){
    return s;
  }
  else{
    return t;
  }
}

// Main function
int main(){
  // Read the input values for n and k from the standard input
  int n,k;
  scanf("%d %d", &n, &k);

  // Initialize a variable to store the sum of the results
  int sum = 0;

  // Iterate through all possible block sizes from 1 to n
  FOR(b, 1, n+1){
    // Calculate the number of blocks of size b that can fit into n+1
    int cnt = (n+1)/b;

    // Calculate the remainder of n+1 when divided by b
    int md = (n+1)%b;

    // Add the number of blocks of size b that cover k or more numbers to the sum
    sum+=cnt*max((b-k),0)+max((md-k),0);

    // If k is 0, subtract 1 from the sum (since an empty block doesn't contribute to the sum)
    if(k==0) sum--;
  }

  // Print the result to the standard output
  printf("%d\n", sum);

  // Return 0 to indicate successful execution
  return 0;
}

