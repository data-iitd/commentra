#include <iostream>

int main() {
  // Declare variables for height and width of the input, and a loop counter
  int height, width, i;

  // Read the height and width from user input
  std::cin >> height >> width;

  // Declare a character array to hold the input strings, with an extra space for the null terminator
  char input_str[width + 1];

  // Print the top border of the box, consisting of '#' characters
  for(i = 0; i < width + 2; i++) {
    std::cout << "#";
  }
  std::cout << "\n";

  // Read each line of input and print it with '#' borders
  for(i = 0; i < height; i++) {
    // Read a string from user input
    std::cin >> input_str;
    // Print the string with '#' on both sides
    std::cout << "#" << input_str << "#\n";
  }

  // Print the bottom border of the box, consisting of '#' characters
  for(i = 0; i < width + 2; i++) {
    std::cout << "#";
  }
  std::cout << "\n";

  // Return 0 to indicate successful completion of the program
  return 0;
}
