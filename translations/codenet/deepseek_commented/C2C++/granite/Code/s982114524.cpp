
#include <iostream>  // Include the standard input/output library

int main(void){  // Define the main function
  int i, N, x;  // Declare integer variables
  x = 0;  // Initialize the variable x to 0
  std::cin >> N;  // Read input from the user and store it in N
  for(i = 1; i <= N; i++)  // Loop through numbers from 1 to N
    x += i;  // Add each number to x
  std::cout << x << std::endl;  // Print the final value of x
  return 0;  // Return 0 to indicate successful execution
}

