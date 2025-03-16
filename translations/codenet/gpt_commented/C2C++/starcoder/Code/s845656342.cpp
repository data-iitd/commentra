#include <iostream>   // Include standard input-output library
#include <cstdlib>    // Include standard library for general functions
#include <cmath>      // Include math library (not used in this code)

using namespace std; // Use standard library

int main(void) // Main function where execution starts
{
  int x; // Declare an integer variable x

  // Read an integer value from user input and store it in x
  cin >> x;

  // Check if the value of x is equal to 1
  if(x == 1) 
    cout << "0" << endl; // If x is 1, print "0"
  else 
    cout << "1" << endl; // If x is not 1, print "1"

  return 0; // Return 0 to indicate successful execution
}

