#include <iostream>
#include <string>

int main() {
    // Declare a string to hold user input
    std::string str;

    // Read a line of input from the user and store it in the str string
    std::getline(std::cin, str);

    // Replace the character at index 5 with a space
    str[5] = ' ';

    // Replace the character at index 13 with a space
    str[13] = ' ';

    // Print the modified string to the console
    std::cout << str << std::endl;

    // Return 0 to indicate successful execution of the program
    return 0;
}
