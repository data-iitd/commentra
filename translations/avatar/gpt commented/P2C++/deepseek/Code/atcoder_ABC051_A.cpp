#include <iostream>
#include <string>

int main() {
    // Prompt the user for input and read the input string
    std::string user_input;
    std::getline(std::cin, user_input);

    // Replace all commas in the input string with spaces
    std::string modified_input = user_input;
    size_t pos = 0;
    while ((pos = modified_input.find(',', pos)) != std::string::npos) {
        modified_input.replace(pos, 1, " ");
        pos += 1; // Move past the space we just added
    }

    // Print the modified input string
    std::cout << modified_input << std::endl;

    return 0;
}
