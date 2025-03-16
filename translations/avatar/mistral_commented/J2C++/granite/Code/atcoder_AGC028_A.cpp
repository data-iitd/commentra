
######
// Include necessary libraries
######
#include <iostream>
#include <string>
#include <cmath>
#include <biginteger.h>  // For handling big integers

using namespace std;

// Main function to start the program
int main() {
  // Read input values for n and m
  int n, m;
  cin >> n >> m;

  // Calculate the greatest common divisor (GCD) of n and m
  int gcd = __gcd(n, m);

  // Read input strings s and t
  string s, t;
  cin >> s >> t;

  // Perform the required calculation and print the result
  long result = -1;
  for (int k = 0; k < gcd; k++) {
    if (s[k * n / gcd]!= t[k * m / gcd]) {
      result = -1;
      break;
    }
  }
  if (result == -1) {
    result = (long long)n * m / gcd;
  }

  // Print the result
  cout << result << endl;

  return 0;
}
