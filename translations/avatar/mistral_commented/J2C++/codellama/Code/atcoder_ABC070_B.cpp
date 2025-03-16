
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Main method is the entry point of the C++ application
int main() {

  // Initialize input and output streams
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  // Read input integers a, b, c, and d
  int a, b, c, d;
  cin >> a >> b >> c >> d;

  // Check if c is greater than b
  if (c > b) {
    // If yes, print 0 and exit
    cout << 0 << endl;
    return 0;
  }

  // Check if a is greater than d
  else if (a > d) {
    // If yes, print 0 and exit
    cout << 0 << endl;
    return 0;
  }

  // Check if a is less than c
  else if (a < c) {
    // If yes, calculate the difference between the smaller and larger of b and d
    int difference = min(b, d) - c;
    // Print the difference
    cout << difference << endl;
    return 0;
  }

  // If none of the above conditions are true, then a, b, c, and d are in sorted order
  else {
    // Create a vector of integers a, b, c, and d
    vector<int> v = {a, b, c, d};

    // Sort the vector in ascending order
    sort(v.begin(), v.end());

    // Calculate the difference between the second and third elements of the vector
    int difference = v[2] - v[1];

    // Print the difference
    cout << difference << endl;
  }

  // End of code
  return 0;
}



