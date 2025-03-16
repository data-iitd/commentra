#include <iostream> // Include the standard input/output header

int main(){ // Define the main function
  int A, B; // Declare two integer variables A and B
  std::cin >> A >> B; // Read two integers from the user and store them in A and B
  if(A < 10 && B < 10) std::cout << A * B << std::endl; // Check if both A and B are less than 10, if true, print the multiplication result
  else std::cout << "-1" << std::endl; // If the condition is false, print -1
  return 0; // Return 0 to indicate successful execution
}

