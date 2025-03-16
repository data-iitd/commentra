#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
  // Read the first integer input from the user
  int a;
  cin >> a;

  // Read the second integer input from the user
  int b;
  cin >> b;

  // Check if the first integer 'a' is positive
  if ( a > 0 ) {
    // If 'a' is positive, print the message "Positive" to the standard output stream
    cout << "Positive" << endl;
  }

  // Else if the second integer 'b' is non-negative
  else if ( b >= 0 ) {
    // If 'b' is non-negative, print the message "Zero" to the standard output stream
    cout << "Zero" << endl;
  }

  // Else if the difference between 'b' and 'a' is even
  else if ( ( b - a + 1 ) % 2 == 0 ) {
    // If the difference is even, print the message "Positive" to the standard output stream
    cout << "Positive" << endl;
  }

  // Else, print the message "Negative" to the standard output stream
  else {
    cout << "Negative" << endl;
  }

  return EXIT_SUCCESS;
}

