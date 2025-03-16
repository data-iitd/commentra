#include<iostream>  // Include the standard input/output library

using namespace std;  // Include the standard namespace

int main() {
  int a, b, c, d;  // Declare four integer variables

  // Read two integer values from the standard input and store them in a and b
  cin >> a >> b;

  // Calculate the product of a and b, and store it in c
  c = a * b;

  // Calculate the perimeter of a rectangle with sides a and b, and store it in d
  d = 2 * a + 2 * b;

  // Print the values of c and d to the standard output
  cout << c << " " << d << endl;

  // Return 0 to indicate successful execution
  return 0;
}
