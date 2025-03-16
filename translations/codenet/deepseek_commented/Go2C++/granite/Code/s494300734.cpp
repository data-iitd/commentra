
#include <iostream>
#include <string>

int main() {
  std::string s; // Declare a string variable to store the input
  
  std::cin >> s; // Read a string from standard input and store it in s
  
  std::string ans = "No"; // Initialize the answer variable with "No"
  
  // Check if 'C' appears before the last occurrence of 'F' in the string s
  if (s.find("C") < s.rfind("F")) {
    ans = "Yes"; // Update ans to "Yes" if the condition is true
  }
  
  // Check if 'C' does not appear in the string s
  if (s.find("C") == std::string::npos) {
    ans = "No"; // Update ans to "No" if the condition is true
  }
  
  std::cout << ans << std::endl; // Print the final value of ans
  
  return 0;
}

