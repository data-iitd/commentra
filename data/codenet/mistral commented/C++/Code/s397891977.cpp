
#include <iostream> // Include the iostream library for input/output operations
#include <vector> // Include the vector container template for dynamic arrays
#include <unordered_map> // Include the unordered_map container template for hash-based associative arrays
#include <unordered_set> // Include the unordered_set container template for hash-based sets
#include <algorithm> // Include the algorithm library for various algorithms on sequences
#include <limits> // Include the limits library for constant definitions related to data types
#include <cmath> // Include the cmath library for mathematical functions
#include <map> // Include the map container template for associative arrays

using namespace std; // Use the standard namespace to avoid having to write "std::" before every standard library object or function

int main() { // The main function is the entry point of the program
  int r; // Declare an integer variable named "r"

  // Read the value of "r" from the standard input using cin
  cin >> r;

  // Output the square of "r" to the standard output using cout and the << operator
  cout << r * r << endl;

  // Use the endl manipulator to insert a newline character after the output

  // The program ends with a return statement, which is not strictly necessary since main returns 0 by default if no return statement is present
  return 0;
}