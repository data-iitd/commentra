

#include <iostream>
#include <cmath>
#include <string>

using namespace std;

// Function to swap two integers
void swap (int *x, int *y) {
  int temp; // Variable to store the temporary value

  temp = *x; // Store the value of x in temp
  *x = *y; // Assign the value of y to x
  *y = temp; // Assign the value of temp (i.e., the original value of x) to y

  return;
}

// Function to find the greatest common divisor (GCD) of two numbers
long int gcd(long int a, long int b){
  long int c; // Variable to store the remainder

  // Continue the division process until the remainder becomes zero
  while (b > 0){
    c = a % b; // Calculate the remainder
    a = b; // Update a with the value of b
    b = c; // Update b with the value of the previous remainder
  }

  return a; // Return the GCD (i.e., the last non-zero value of a)
}

// Comparator function for std::sort() to sort in ascending order
bool upll(const long long& a, const long long& b){
  return a<b;
}

// Comparator function for std::sort() to sort in descending order
bool downll(const long long& a, const long long& b){
  return a>b;
}

// Function to sort an array in ascending order using std::sort()
void sortup(long long*a,int n){
  std::sort(a,a+n);
}

// Function to sort an array in descending order using std::sort()
void sortdown(long long*a,int n){
  std::sort(a,a+n,std::greater<long long>());
}

// Function to calculate a^n modulo m
long long modpow(long long a,long long n,long long mod){
  long long ans=1; // Initialize the answer as 1
  while(n>0){
    if(n & 1){ // Check if n is odd
      ans=ans*a%mod; // Multiply the answer with a and take modulo m
    }
    a=a*a%mod; // Square a and take modulo m
    n/=2; // Divide n by 2
  }
  return ans; // Return the final answer
}

// Function to find the modular multiplicative inverse of a modulo m
long long modinv(long long a,long long mod){
  return modpow(a,mod-2,mod);
}

// Function to find the maximum of two integers
int max(int a,int b){
  if(a<b){ // If a is smaller than b
    return b; // Return b as the maximum
  }
  else{ // If a is greater than or equal to b
    return a; // Return a as the maximum
  }
}

// Function to find the minimum of two integers
int min(int a,int b){
  if(a<b){ // If a is smaller than b
    return a; // Return a as the minimum
  }
  else{ // If a is greater than or equal to b
    return b; // Return b as the minimum
  }
}

// Function to update the value of a variable with the maximum of the current value and a new value
void chmax(int *a,int b){
  if(*a < b){ // If the current value is smaller than the new value
    *a = b; // Update the current value with the new value
  }

  return;
}

// Function to update the value of a variable with the minimum of the current value and a new value
void chmin(int *a,int b){
  if(*a > b){ // If the current value is greater than the new value
    *a =b; // Update the current value with the new value
  }

  return;
}

// Main function
int main(void){
  int n; // Variable to store the number of digits in the given number
  int sum=0; // Variable to store the sum of digits
  long long m; // Variable to store the given number

  // Read the number of digits from the standard input
  cin >> n;

  // Initialize m with the given number
  m = n;

  // Calculate the sum of digits
  for(int i=0;i<9;i++){
    sum+=m%10; // Add the last digit to the sum
    m/=10; // Remove the last digit and update m
  }

  // Check if the given number is divisible by the sum of its digits
  if(m%sum==0){
    cout << "Yes" << endl; // If yes, print "Yes"
  }else{
    cout << "No" << endl; // If no, print "No"
  }

  return 0; // Return 0 to indicate successful execution
}

// The above code now includes comments for each logical block. These comments should help in understanding the code better.