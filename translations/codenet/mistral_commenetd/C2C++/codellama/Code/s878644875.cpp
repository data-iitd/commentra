#include <iostream> // Include the standard input/output library

int main(void) // Declare the main function with no arguments and no return value
{
  char s[4], t[4]; // Declare two character arrays of size 4
  std::cin >> s; // Read a string of length less than or equal to 3 from the standard input and store it in array s
  std::cin >> t; // Read a string of length less than or equal to 3 from the standard input and store it in array t
  int hit = 0; // Initialize a counter variable hit to 0
  for (int i = 0; i < 3; i++){ // Start a for loop that iterates from 0 to 2 (3 times)
    if (s[i] == t[i]) hit++; // If the i-th character of string s is equal to the i-th character of string t, increment the counter variable hit
  }
  std::cout << hit << std::endl; // Print the value of the counter variable hit to the standard output followed by a newline character
  return 0; // Indicate that the main function has terminated successfully with a return value of 0
}

