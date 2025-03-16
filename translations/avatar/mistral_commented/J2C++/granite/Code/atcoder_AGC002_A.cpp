
// Include the necessary header file for input/output operations
#include <iostream>

// Define the main function as the entry point of the program
int main ( ) {
  // Create a new stream object to read input from the standard input stream
  std::cin >> a >> b ;

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

  // End of code
  return 0 ;
}
