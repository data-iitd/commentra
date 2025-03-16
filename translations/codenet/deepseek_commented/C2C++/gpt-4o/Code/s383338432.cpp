#include <iostream>  // Include the iostream library for input and output
#include <string>    // Include the string library for using std::string

int main() {
    int height, width;  // Declare integer variables for height and width
    std::cin >> height >> width;  // Read the height and width from the user input
    std::string input_str;  // Declare a string to store the input string

    // Print the top border of the output
    for(int i = 0; i < width + 2; i++) {
        std::cout << "#";
    }
    std::cout << std::endl;

    // Read and print each line of input with borders
    for(int i = 0; i < height; i++) {
        std::cin >> input_str;  // Read a string from the user
        std::cout << "#" << input_str << "#" << std::endl;  // Print the string with borders
    }

    // Print the bottom border of the output
    for(int i = 0; i < width + 2; i++) {
        std::cout << "#";
    }
    std::cout << std::endl;

    return 0;  // Return 0 to indicate successful program termination
}  // <END-OF-CODE>
