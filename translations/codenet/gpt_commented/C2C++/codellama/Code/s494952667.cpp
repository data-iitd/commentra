#include <iostream>
#include <string>

int main()
{
  // Declare a string to hold the input string
  std::string str;
  int i, len;
  
  // Read a string from standard input
  std::cin >> str;
  
  // Calculate the length of the input string
  len = str.length();

  // Loop through the string in reverse order
  for(i = len - 1; i >= 0; i--){
    // Output each character of the string in reverse
    std::cout << str[i];
  }
  
  // Print a newline character after the reversed string
  std::cout << std::endl;
  
  // Return 0 to indicate successful completion of the program
  return 0;
}

