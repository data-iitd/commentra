
#include <iostream>

int main() {
  // Initialize a for loop that will iterate 5 times
  for (int i = 0; i < 5; i++) {
    // Declare and initialize a variable 'a' to store user input
    int a;

    // Request user input and store it in variable 'a'
    std::cin >> a;

    // Check if the user input is equal to zero
    if (a == 0) {
      // If user input is zero, print the current iteration number
      std::cout << i + 1 << std::endl;
    }
  }

  return 0;
}

