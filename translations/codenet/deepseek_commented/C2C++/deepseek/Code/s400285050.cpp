#include <iostream>  // Include the standard input/output stream library

int you(int, int);  // Function declaration for the you function

int main() {  // Main function is the entry point of the program
  int x, y, z;  // Declare three integer variables
  std::cin >> x >> y;  // Read two integers from standard input
  if (x >= y)  // Check if x is greater than or equal to y
    z = you(x, y);  // Call the you function with x and y as arguments
  else  // Otherwise
    z = you(y, x);  // Call the you function with y and x as arguments
  std::cout << z << std::endl;  // Print the result to standard output
  return 0;  // Return 0 to indicate successful execution
}

int you(int x, int y) {  // Define the you function
  int z;  // Declare an integer variable to store intermediate results
  while (true) {  // Infinite loop to apply the Euclidean algorithm
    z = x % y;  // Compute the remainder of x divided by y
    x = y;  // Update x to be the previous value of y
    y = z;  // Update y to be the remainder
    if (y <= 0)  // Check if y is zero or negative
      break;  // Exit the loop if y is zero or negative
  }
  return x;  // Return the GCD of the original two numbers
}

