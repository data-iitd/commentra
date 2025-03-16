#include <iostream> // Include the standard input/output library
#include <string> // Include the string library

int main() // Declare the main function with no arguments and no return value
{
  std::string s, t; // Declare two string variables
  std::cin >> s; // Read a string from the standard input and store it in variable s
  std::cin >> t; // Read a string from the standard input and store it in variable t
  int hit = 0; // Initialize a counter variable hit to 0
  for (int i = 0; i < 3; i++){ // Start a for loop that iterates from 0 to 2 (3 times)
    if (s[i] == t[i]) hit++; // If the i-th character of string s is equal to the i-th character of string t, increment the counter variable hit
  }
  std::cout << hit << std::endl; // Print the value of the counter variable hit to the standard output followed by a newline character
  return 0; // Indicate that the main function has terminated successfully with a return value of 0
}
