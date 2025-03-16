#include <iostream> // Include iostream library for input/output operations
#include <string> // Include string library for string manipulation

int main(){ // Start of the main function
  int n; // Declare an integer variable 'n' to store the number of strings to be processed
  std::string s; // Declare a string variable 's' to store each string read from the input

  std::cin >> n; // Read an integer 'n' from the standard input
  std::cin.ignore(); // Ignore the newline character after reading 'n'

  while(n--){ // Start of the while loop that processes each string
    std::getline(std::cin, s); // Read a string from the standard input into the string variable 's'

    size_t pos = 0; // Declare a size_t variable 'pos' to store the position of the substring "Hoshino"
    while((pos = s.find("Hoshino", pos)) != std::string::npos){ // Start of the inner while loop that replaces the substring "Hoshino" with "aana"
      s.replace(pos, 7, "aana"); // Replace the substring "Hoshino" with "aana"
      pos += 4; // Move the position to the end of the replaced substring to avoid infinite loop
    }

    std::cout << s << std::endl; // Print the modified string to the standard output
  }

  return 0; // End of the main function with a return value of 0 indicating successful execution
}
