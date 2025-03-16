#include <iostream>
using namespace std;

int main() {
  // Declare three integer variables A, B, and C
  int A, B, C;

  // Read three integers from user input and store them in A, B, and C
  cin >> A >> B >> C;

  // Check if C is between A and B (A < C < B)
  if (A < C && C < B) {
    // If true, print "Yes"
    cout << "Yes" << endl;
  } 
  // Check if C is between B and A (A > C > B)
  else if (A > C && C > B) {
    // If true, print "Yes"
    cout << "Yes" << endl;
  } 
  // If neither condition is met, print "No"
  else {
    cout << "No" << endl;
  }
}
