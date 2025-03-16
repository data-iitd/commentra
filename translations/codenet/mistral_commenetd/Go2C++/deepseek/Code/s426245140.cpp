#include <iostream>
#include <string>

int main() {
  std::string s;

  // Use "std::cin" to read a string input from the standard input
  std::cin >> s;

  // Check if the first three characters of the string "s" form an identical sequence
  if (s[0] == s[1] && s[1] == s[2] || s[1] == s[2] && s[2] == s[3]) {
    // If the condition is true, print "Yes" to the standard output
    std::cout << "Yes" << std::endl;
  } else {
    // If the condition is false, print "No" to the standard output
    std::cout << "No" << std::endl;
  }

  return 0;
}

