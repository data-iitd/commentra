#include <iostream>  // Include the standard input/output library

int main(){  // Define the main function
  int x, a;  // Declare integer variables
  std::cin >> x >> a;  // Read input values
  std::cout << ((x >= a) * 10) << std::endl;  // Perform a comparison and multiplication, then print the result
  return 0;  // Return from main
}
