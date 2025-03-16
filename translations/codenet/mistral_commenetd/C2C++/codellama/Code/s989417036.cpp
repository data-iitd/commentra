#include <iostream>
using namespace std;

int main() {
  // Declare variables
  int a, b, c, d, e, i;

  // Initialize variables with cin
  cin >> a >> b >> c;

  // Check if b is less than or equal to c
  if (b <= c) {
    // If so, print "NO" and exit
    cout << "NO" << endl;
    return 0;
  }

  // Else, continue with the following logic
  else {
    // Initialize d with a and e with the remainder of a divided by b
    d = a;
    e = d % b;

    // Iterate through b using a for loop
    for (i = 0; i < b; i++) {
      // Update d by calculating the remainder of d divided by b
      d = d % b;

      // If d is equal to c, print "YES" and exit
      if (d == c) {
        cout << "YES" << endl;
        return 0;
      }

      // If d is already equal to c and i is not the first iteration, print "NO" and exit
      else if (i != 0 && d == c) {
        cout << "NO" << endl;
        return 0;
      }

      // Update d by adding a
      d += a;
    }
  }

  // If the loop finishes without finding c, print "NO" and exit
  cout << "NO" << endl;
  return 0;
}

