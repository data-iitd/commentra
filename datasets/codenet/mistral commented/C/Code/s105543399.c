#include <stdio.h> // We include the standard input/output library

int main() { // The main function is the entry point of the program
  long long n, a, m, M, c, b, i; // We declare variables of type long long for numbers that can be very large
  long long c = 0; // We initialize the variable 'c' to zero
  long long m = 100000000; // We initialize 'm' to a very large negative number
  long long M =-100000000; // We initialize 'M' to a very large positive number

  // We read the first number 'n' from the standard input
  scanf("%lld",&n);

  for(i=1; i<=n; i++){ // We start a for loop that iterates 'n' times
    long long a; // We declare a variable 'a' to store the current number

    // We read the current number 'a' from the standard input
    scanf("%lld",&a);

    // If the current number 'a' is greater than the current maximum number 'M', we update 'M' with 'a'
    if(a>M) {
      M = a;
    }

    // If the current number 'a' is smaller than the current minimum number 'm', we update 'm' with 'a'
    if(a < m){
      m = a;
    }

    // We add the current number 'a' to the variable 'c'
    c = c+a;
  }

  // We print the minimum number 'm', the maximum number 'M', and the sum 'c' to the standard output
  printf("%lld %lld %lld\n",m,M,c);

  // The main function returns zero to indicate successful execution
  return 0;
}
