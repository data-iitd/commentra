#include <iostream>
#include <string>
#include <algorithm>

int main() {
    // Prompt the user for input
    std::string user_input;
    std::getline(std::cin, user_input);

    // Replace all commas in the input string with spaces
    std::replace(user_input.begin(), user_input.end(), ',', ' ');

    // Print the modified input string
    std::cout << user_input << std::endl;

    return 0;
}

// <END-OF-CODE>
