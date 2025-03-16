

#include <iostream>

// Declare three integer variables 'a', 'b', and 'c'
int main(void) {
  int a, b, c;

  // Read three integers from the standard input using cin
  std::cin >> a >> b >> c;

  // Check if the condition 'b > a * c' is true
  if (b > a * c) {
    // If the condition is true, print the value of 'c'
    std::cout << c << std::endl;
  } else {
    // If the condition is false, calculate the integer division of 'b' by 'a'
    // and print the result
    std::cout << b / a << std::endl;
  }

  // Return 0 to indicate successful execution of the program
  return 0;
}

