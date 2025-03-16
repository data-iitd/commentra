#include <iostream> // Step 1: Include necessary headers
#include <cmath>    // for mathematical functions

int main() // Step 2: Define the main function
{
  int x; // Step 3: Declare an integer variable
  std::cin >> x; // Step 4: Read an integer value from the user

  if (x == 1) // Step 5: Implement a simple if-else statement
    std::cout << "0\n"; // Print 0 if the input is 1
  else
    std::cout << "1\n"; // Print 1 if the input is not 1

  return 0; // Step 6: Return 0 to indicate successful execution
}

