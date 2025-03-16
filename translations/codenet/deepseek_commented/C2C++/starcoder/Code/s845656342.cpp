#include <iostream> // Step 1: Include necessary headers
#include <cstdlib>  // for standard library functions
#include <cmath>    // for mathematical functions

using namespace std; // Step 2: Use the standard library namespace

int main(void) // Step 3: Define the main function
{
  int x; // Step 4: Declare an integer variable
  cin >> x; // Step 5: Read an integer value from the user

  if (x == 1) // Step 6: Implement a simple if-else statement
    cout << "0" << endl; // Print 0 if the input is 1
  else
    cout << "1" << endl; // Print 1 if the input is not 1

  return 0; // Step 7: Return 0 to indicate successful execution
}

