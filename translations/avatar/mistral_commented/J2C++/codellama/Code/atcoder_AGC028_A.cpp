#######
// Import necessary libraries
#######
#include <iostream>
#include <cmath>
#include <string>

using namespace std;

// Main method to start the program
int main() {
  // Read input values for n and m
  int n, m;
  cin >> n >> m;

  // Calculate the greatest common divisor (GCD) of n and m
  int gcd = gcd(n, m);

  // Read input strings s and t
  string s, t;
  cin >> s >> t;

  // Perform the required calculation and print the result
  long result = 0;
  for (int k = 0; k < gcd; k++) {
    if (s[k * n / gcd] != t[k * m / gcd]) {
      result = -1;
      break;
    }
  }
  if (result == 0) {
    result = n * m / gcd;
  }

  // Print the result
  cout << result << endl;

  return 0;
}

// Function to calculate the greatest common divisor (GCD) of two integers
int gcd(int a, int b) {
  if (b == 0) {
    return a;
  } else {
    return gcd(b, a % b);
  }
}

