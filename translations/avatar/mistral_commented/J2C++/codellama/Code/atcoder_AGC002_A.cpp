// Include the iostream header file
#include <iostream>

// Define the main function as the entry point of the program
int main ( ) {
  // Declare two integer variables 'a' and 'b'
  int a, b ;

  // Read the first integer input from the user
  std::cin >> a ;

  // Read the second integer input from the user
  std::cin >> b ;

  // Check if the first integer 'a' is positive
  if ( a > 0 ) {
    // If 'a' is positive, print the message "Positive" to the standard output stream
    std::cout << "Positive" << std::endl ;
  }

  // Else if the second integer 'b' is non-negative
  else if ( b >= 0 ) {
    // If 'b' is non-negative, print the message "Zero" to the standard output stream
    std::cout << "Zero" << std::endl ;
  }

  // Else if the difference between 'b' and 'a' is even
  else if ( ( b - a + 1 ) % 2 == 0 ) {
    // If the difference is even, print the message "Positive" to the standard output stream
    std::cout << "Positive" << std::endl ;
  }

  // Else, print the message "Negative" to the standard output stream
  else {
    std::cout << "Negative" << std::endl ;
  }

  // Return 0 to indicate that the program completed successfully
  return 0 ;
}

