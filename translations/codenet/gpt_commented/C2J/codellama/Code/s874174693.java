#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define ll long long

// Function to swap two integers
void swap (int *x, int *y) {
  int temp;

  // Swap the values of x and y
  temp = *x;
  *x = *y;
  *y = temp;

  return;
}

// Function to compute the greatest common divisor (GCD) of two numbers
long int gcd(long int a, long int b){
  long int c;

  // Use the Euclidean algorithm to find GCD
  while (b > 0){
    c = a % b;
    a = b;
    b = c;
  }

  return a; // Return the GCD
}

// Comparison function for sorting in ascending order
int upll(const void*a, const void*b){
  return*(ll*)a<*(ll*)b?-1:*(ll*)a>*(ll*)b?1:0;
}

// Comparison function for sorting in descending order
int downll(const void*a, const void*b){
  return*(ll*)a<*(ll*)b?1:*(ll*)a>*(ll*)b?-1:0;
}

// Function to sort an array in ascending order
void sortup(ll*a,int n){
  qsort(a,n,sizeof(ll),upll); // Use qsort with the ascending comparison function
}

// Function to sort an array in descending order
void sortdown(ll*a,int n){
  qsort(a,n,sizeof(ll),downll); // Use qsort with the descending comparison function
}

// Function to compute modular exponentiation
long int modpow(long int a,long int n,long int mod){
  long int ans=1;

  // Exponentiation by squaring method
  while(n>0){
    if(n & 1){ // If n is odd
      ans=ans*a%mod; // Multiply the base with the result
    }
    a=a*a%mod; // Square the base
    n/=2; // Divide n by 2
  }
  return ans; // Return the result
}

// Function to compute modular inverse using Fermat's little theorem
long int modinv(long int a,long int mod){
  return modpow(a,mod-2,mod); // a^(mod-2) mod mod
}

// Function to return the maximum of two integers
int max(int a,int b){
  if(a<b){
    return b; // Return b if a is less than b
  }
  else{
    return a; // Otherwise return a
  }
}

// Function to return the minimum of two integers
int min(int a,int b){
  if(a<b){
    return a; // Return a if it is less than b
  }
  else{
    return b; // Otherwise return b
  }
}

// Function to update the value of a if b is greater
void chmax(int *a,int b){
  if(*a < b){
    *a = b; // Update a to b if b is greater
  }

  return;
}

// Function to update the value of a if b is smaller
void chmin(int *a,int b){
  if(*a > b){
    *a = b; // Update a to b if b is smaller
  }

  return;
}

// Main function
int main(void){
  int n;
  // Read an integer n from input
  scanf("%d",&n);
  int sum=0; // Initialize sum to 0
  int m=n; // Store the original value of n

  // Calculate the sum of the digits of n (up to 9 digits)
  for(int i=0;i<9;i++){
    sum+=n%10; // Add the last digit to sum
    n/=10; // Remove the last digit
  }

  // Check if m is divisible by the sum of its digits
  if(m%sum==0){
    printf("Yes\n"); // Print "Yes" if divisible
  }else{
    printf("No\n"); // Print "No" if not divisible
  }
  
  return 0; // Return success
}

