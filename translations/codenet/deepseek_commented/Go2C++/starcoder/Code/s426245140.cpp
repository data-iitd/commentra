#include <iostream>

int main() {
  // Declare a variable to store the input string
  std::string s;
  
  // Read a string input from the user and store it in `s`
  std::cin >> s;
  
  // Check if the first three characters of `s` are the same or if the second three characters of `s` are the same
  if (s[0] == s[1] && s[1] == s[2]) || (s[1] == s[2] && s[2] == s[3]){
    // If either condition is true, print "Yes"
    std::cout << "Yes" << std::endl;
  } else {
    // Otherwise, print "No"
    std::cout << "No" << std::endl;
  }
}

