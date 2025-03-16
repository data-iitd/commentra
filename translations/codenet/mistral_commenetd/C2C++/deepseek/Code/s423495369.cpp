#include <iostream>
using namespace std;

// Declare three integer variables A, B, and C
int main () {
  int A, B, C;

  // Read three integers from the standard input using cin function
  cin >> A >> B >> C;

  // Check if A is less than C and C is less than B
  if (A < C && C < B) {
    // If condition is true, print "Yes" to the standard output
    cout << "Yes" << endl;
  } // End of first if block

  // Else if condition checks if A is greater than C and C is greater than B
  else if (A > C && C > B) {
    // If condition is true, print "Yes" to the standard output
    cout << "Yes" << endl;
  } // End of second if block

  // Else condition is executed when neither first nor second condition is true
  else {
    // If condition is false, print "No" to the standard output
    cout << "No" << endl;
  } // End of else block
} // End of main function

