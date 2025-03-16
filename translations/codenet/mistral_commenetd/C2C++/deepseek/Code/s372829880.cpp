#include <iostream>

// Declare the main function
int main(){
  // Declare and initialize two integer variables, x and a
  int x, a;

  // Read data from the standard input stream and store it into x and a
  std::cin >> x >> a;

  // Check if x is greater than or equal to a
  int result = (x >= a);

  // Multiply the result by 10
  result *= 10;

  // Print the result to the standard output stream
  std::cout << result << std::endl;

  // Return 0 to indicate successful execution
  return 0;
}

