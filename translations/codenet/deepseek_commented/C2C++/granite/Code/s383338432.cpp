
#include <iostream>  // Include the standard input-output library for cout and cin

int main() {
  int height, width, i;  // Declare integer variables for height, width, and loop index
  std::cin >> height >> width;  // Read the height and width from the user input
  char input_str[width+1];  // Declare a character array to store the input string

  // Print the top border of the output
  for(i = 0; i < width + 2; i++) {
    std::cout << "#";
  }
  std::cout << std::endl;

  // Read and print each line of input with borders
  for(i = 0; i < height; i++) {
    std::cin >> input_str;  // Read a string from the user
    std::cout << "#" << input_str << "#" << std::endl;  // Print the string with borders
  }

  // Print the bottom border of the output
  for(i = 0; i < width + 2; i++) {
    std::cout << "#";
  }
  std::cout << std::endl;

  return 0;  // Return 0 to indicate successful program termination
}
