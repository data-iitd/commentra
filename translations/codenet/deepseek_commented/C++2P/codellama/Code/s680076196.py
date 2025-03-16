#include <iostream>  # Step 1: Include necessary headers for input/output operations
#include <algorithm> # Not explicitly needed for this code but can be useful for other operations
#include <cmath>     # Step 1: Include headers for mathematical operations
using namespace std; # Step 1: Avoid using the std namespace directly for better readability

typedef long long ll; # Step 2: Define a type for long long integers to handle large numbers

int main(): # Step 3: Read input values
  int a, b, c, d; # Declare variables to store the input values
  cin >> a >> b >> c >> d; # Read the four integer values from the user

  # Step 4: Perform calculations
  int area = (a - c) * (b - d); # Calculate the area of the rectangle using the given coordinates

  # Step 5: Output the result
  cout << area << endl; # Print the calculated area to the console

