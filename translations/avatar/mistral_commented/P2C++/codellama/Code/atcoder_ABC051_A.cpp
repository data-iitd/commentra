
#include <iostream>
#include <string>

int main()
{
    // Read a line from input using the getline function
    std::string input_string;
    std::getline(std::cin, input_string);

    // Replace all commas with spaces in the input string
    std::string modified_string = input_string.replace(input_string.begin(), input_string.end(), ',', ' ');

    // Print the modified string to the console
    std::cout << modified_string << std::endl;

    return 0;
}

