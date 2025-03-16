#include <iostream>
#include <string>

int main() {
  // Declare a variable to hold the input string
  std::string s;
  
  // Read input from the user and store it in the variable 's'
  std::cin >> s;
  
  // Check if the first three characters are the same or the last three characters are the same
  if ((s[0] == s[1] && s[1] == s[2]) || (s[1] == s[2] && s[2] == s[3])) {
    // If the condition is true, print "Yes"
    std::cout << "Yes" << std::endl;
  } else {
    // If the condition is false, print "No"
    std::cout << "No" << std::endl;
  }
  
  return 0;
}

