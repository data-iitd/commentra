
// Importing necessary C++ libraries
#include <iostream>
#include <string>

// Main method is the entry point of the C++ application
int main() {
    try {
        // Creating a string variable to store the input from the console
        std::string input;

        // Reading a line of input from the console and storing it in the 'input' variable
        std::getline(std::cin, input);

        // Tokenizing the input string into an array of strings using space as delimiter
        std::string delimiter = " ";
        size_t pos = 0;
        std::string token;
        std::vector<std::string> tokens;
        while ((pos = input.find(delimiter))!= std::string::npos) {
            token = input.substr(0, pos);
            tokens.push_back(token);
            input.erase(0, pos + delimiter.length());
        }
        tokens.push_back(input);

        // Parsing the first and second elements of the input array into integers 'a' and 'b' respectively
        int a = std::stoi(tokens[0]);
        int b = std::stoi(tokens[1]);

        // Calculate the value of 'c' by subtracting 'b' multiplied by 2 from 'a'
        int c = a - b * 2;

        // If the value of 'c' is negative, set it to zero
        if (c < 0) {
            c = 0;
        }

        // Print the value of 'c' to the console
        std::cout << c << std::endl;
    } catch (std::exception& e) {
        // Handling any exceptions that might occur during the execution of the program
    }

    return 0;
}
