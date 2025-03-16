
#include <iostream>
#include <string>

int main() {
    std::string user_input;
    std::cout << "Enter a string: ";
    std::getline(std::cin, user_input);

    std::string modified_input = user_input;
    for (size_t i = 0; i < modified_input.length(); i++) {
        if (modified_input[i] == ',') {
            modified_input[i] ='';
        }
    }

    std::cout << "Modified input: " << modified_input << std::endl;

    return 0;
}

