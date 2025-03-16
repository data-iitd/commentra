
#include <iostream>
#include <string>

int main()
{
  // Declare a string variable to hold the input string
  std::string str;
  
  // Read a string from standard input
  std::cin >> str;
  
  // Calculate the length of the input string
  int len = str.length();

  // Loop through the string in reverse order
  for(int i = len - 1; i >= 0; i--){
    // Output each character of the string in reverse
    std::cout << str[i];
  }
  
  // Print a newline character after the reversed string
  std::cout << "\n";
  
  // Return 0 to indicate successful completion of the program
  return 0;
}
