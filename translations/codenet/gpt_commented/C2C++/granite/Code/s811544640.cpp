
#include <iostream>

int main() {
  // Declare three integer variables a, b, and c
  int a, b, c;

  // Read three integers from user input
  std::cin >> a >> b >> c;

  // Check if b is greater than the product of a and c
  if (b > a * c) {
    // If true, print the value of c
    std::cout << c << std::endl;
  } else {
    // If false, print the result of b divided by a
    std::cout << b / a << std::endl;
  }

  // Return 0 to indicate successful execution of the program
  return 0;
}
