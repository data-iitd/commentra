#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Function to compute the greatest common divisor (GCD) of two numbers
long long gcd(long long x, long long y) {
  long long tmp = 0;
  // Ensure x is greater than or equal to y
  if (x < y){
    tmp = x;
    x = y;
    y = tmp;
  }
  // Apply the Euclidean algorithm to find GCD
  while (y > 0) {
    long long r = x % y;
    x = y;
    y = r;
  }
  return x; // Return the GCD
}

// Function to compute the least common multiple (LCM) of two numbers
long long lcm(long long x, long long y){
  return x / gcd(x, y) * y; // LCM formula using GCD
}

// Function to compute the factorial of a number modulo 1,000,000,007
long long kaijo(long long k){
    long long sum = 1;
    // Calculate factorial iteratively
    for (long long i = 1; i <= k; ++i)
    {
        sum *= i; // Multiply current sum by i
        sum %= 1000000000 + 7; // Take modulo to prevent overflow
    }
    return sum; // Return the factorial
}

// Function to return the maximum of two numbers
long long lmax(long long s, long long t){
  if(s > t){
    return s; // Return s if it is greater
  }
  else{
    return t; // Otherwise return t
  }
}

// Function to return the minimum of two numbers
long long lmin(long long s, long long t){
  if(s < t){
    return s; // Return s if it is smaller
  }
  else{
    return t; // Otherwise return t
  }
}

// Main function to execute the program
int main(){
  int n, k;
  // Input the values of n and k
  scanf("%d %d", &n, &k);
  long long sum = 0; // Initialize sum to zero

  // Loop through each integer b from 1 to n
  for(int b = 1; b <= n; b++){
    // Calculate the count of multiples of b in the range [1, n]
    int cnt = (n + 1) / b;
    // Calculate the remainder when n + 1 is divided by b
    int md = (n + 1) % b;
    // Update the sum based on the count and the maximum values
    sum += cnt * lmax((b - k), 0) + lmax((md - k), 0);
    // Adjust the sum if k is zero
    if(k == 0) sum--;
  }
  
  // Output the final computed sum
  printf("%lld\n", sum);
  return 0; // End of the program
}
