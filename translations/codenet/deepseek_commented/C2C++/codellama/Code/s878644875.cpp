#include <iostream> // Include necessary headers for cin and cout

int main() // Define the main function
{
  char s[4], t[4]; // Declare character arrays to store input strings
  std::cin >> s; // Read the first string from the user and store it in s
  std::cin >> t; // Read the second string from the user and store it in t
  int hit = 0; // Initialize a counter for hits
  for (int i = 0; i < 3; i++){ // Compare characters in the strings
    if (s[i] == t[i]) hit++; // Increment the hit counter if characters match
  }
  std::cout << hit << std::endl; // Print the number of matching characters
  return 0; // Return from the main function
}

