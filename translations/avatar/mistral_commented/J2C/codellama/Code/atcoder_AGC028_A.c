#######
// Include necessary libraries
#######
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Define a structure to store the input values
struct Input {
  int n;
  int m;
  char s[100000];
  char t[100000];
};

// Define a function to calculate the greatest common divisor (GCD) of two integers
int gcd(int a, int b) {
  if (b == 0) {
    return a;
  } else {
    return gcd(b, a % b);
  }
}

// Define a function to perform the required calculation
long calculate(struct Input input) {
  // Calculate the GCD of n and m
  int gcd = gcd(input.n, input.m);

  // Initialize a variable to store the result
  long result = 0;

  // Iterate over the range of values of k
  for (int k = 0; k < gcd; k++) {
    // If the characters at the k-th position in s and t are not equal,
    // then increment the result by -1
    if (input.s[k * input.n / gcd] != input.t[k * input.m / gcd]) {
      result -= 1;
    }
  }

  // If the result is 0, then return the product of n and m divided by the GCD
  if (result == 0) {
    return (long)input.n * input.m / gcd;
  } else {
    // Otherwise, return the result
    return result;
  }
}

// Define a function to read the input values
void readInput(struct Input *input) {
  // Read the values of n and m
  scanf("%d %d", &input->n, &input->m);

  // Read the strings s and t
  scanf("%s %s", input->s, input->t);
}

// Define a function to print the result
void printResult(long result) {
  // Print the result
  printf("%ld\n", result);
}

// Main function to start the program
int main() {
  // Initialize a variable to store the input values
  struct Input input;

  // Read the input values
  readInput(&input);

  // Calculate the result
  long result = calculate(input);

  // Print the result
  printResult(result);

  // End the program
  return 0;
}

