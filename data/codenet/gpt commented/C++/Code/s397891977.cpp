#include <iostream>      // Include the input-output stream library for console I/O
#include <vector>       // Include the vector library for using dynamic arrays (not used in this code)
#include <unordered_map> // Include the unordered_map library for hash table based maps (not used in this code)
#include <unordered_set> // Include the unordered_set library for hash table based sets (not used in this code)
#include <algorithm>    // Include the algorithm library for various algorithms (not used in this code)
#include <limits>       // Include the limits library for numeric limits (not used in this code)
#include <cmath>        // Include the cmath library for mathematical functions (not used in this code)
#include <map>          // Include the map library for ordered maps (not used in this code)

using namespace std;

int main() {
  int r; // Declare an integer variable 'r' to store the radius

  // Read the radius value from user input
  cin >> r;

  // Calculate the area of the circle using the formula πr²
  // Here, we are using the simplified version by omitting π for demonstration
  cout << (r * r) << endl; // Output the calculated area (r squared)

  return 0; // Return 0 to indicate successful completion of the program
}
