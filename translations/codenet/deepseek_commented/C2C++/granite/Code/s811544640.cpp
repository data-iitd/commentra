
#include <iostream>  // Step 1: Include necessary headers

int main(void) {  // Step 2: Define the main function
  int a, b, c;  // Step 3: Declare variables

  std::cin >> a >> b >> c;  // Step 4: Read input values

  if (b > a * c) {  // Step 5: Implement the if-else condition
    std::cout << c << std::endl;  // If true, print c
  } else {
    std::cout << b / a << std::endl;  // Otherwise, print b divided by a
  }

  return 0;  // Step 6: Return 0 to indicate successful execution
}

