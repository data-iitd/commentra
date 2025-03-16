#include <iostream>
#include <numeric> // For std::gcd
#include <string>
#include <vector>

using namespace std;

int main() {
  // Initialize a Scanner object for reading input
  int n, m;
  cin >> n >> m;

  // Calculate the greatest common divisor (GCD) of n and m
  int gcd = gcd(n, m);

  // Read input strings s and t
  string s, t;
  cin >> s >> t;

  // Perform the required calculation and print the result
  long result = 0;
  for (int k = 0; k < gcd; ++k) {
    if (s[k * n / gcd] != t[k * m / gcd]) {
      result = -1;
      break;
    }
  }

  if (result == -1) {
    long long lcm = static_cast<long long>(n) * m / gcd;
    result = lcm;
  }

  // Print the result
  cout << result << endl;

  return 0;
}
