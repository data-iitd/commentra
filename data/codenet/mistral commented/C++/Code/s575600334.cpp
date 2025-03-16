#include <iostream>
#include <cstdio>

using namespace std;

// Function to print binary representation of a number
void binPrint(int x, int bits){
  // Iterate through each bit starting from the last one
  for (int i = bits - 1; i >= 0; i--){
    // Print the bit value based on the bitwise AND operation with the mask (1<<i)
    cout << (x & (1<<i) ? 1 : 0);
  }
  // Print newline character after printing the binary number
  cout << endl;
}

int main(void){
  // Declare unsigned integer variables a and b
  unsigned a, b;

  // Read integer values of a and b from the standard input
  cin >> a >> b;

  // Print binary representation of bitwise AND of a and b
  binPrint(a & b, 32);

  // Print binary representation of bitwise OR of a and b
  binPrint(a | b, 32);

  // Print binary representation of bitwise XOR of a and b
  binPrint(a ^ b, 32);

  // Return 0 to indicate successful execution of the program
  return 0;
}
