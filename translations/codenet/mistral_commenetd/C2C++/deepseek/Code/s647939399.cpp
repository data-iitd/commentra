#include <iostream>
using namespace std;

int main() {
  char m; // Declare character variable m
  int a, b; // Declare integer variables a and b
  int c[256]; // Declare array c of size 256
  int i = 0; // Declare and initialize integer variable i

  // Initialize array c with zeros
  for(int i = 0; i < 256; i++) {
    c[i] = 0;
  }

  // Read input values of a, m, and b from the user
  while (true) {
    cin >> a >> m >> b;

    // Check if the user has entered '?' to terminate the loop
    if(m == '?') {
      break;
    }

    // Perform arithmetic operations based on the operator m
    if(m == '+') {
      c[i] = a + b; // Store the result of addition in the array c
    }
    if(m == '-') {
      c[i] = a - b; // Store the result of subtraction in the array c
    }
    if(m == '*') {
      c[i] = a * b; // Store the result of multiplication in the array c
    }
    if(m == '/') {
      c[i] = a / b; // Store the result of division in the array c
    }

    i++; // Increment the index i
  }

  // Print the results of the arithmetic operations
  for(int j = 0; j < i; j++) {
    cout << c[j] << endl;
  }

  return 0;
}
