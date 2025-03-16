

#include <iostream>
#include <string>

int main() {
    std::string input_string;
    std::getline(std::cin, input_string);

    std::string modified_string = input_string;
    for (size_t i = 0; i < modified_string.length(); i++) {
        if (modified_string[i] == ',') {
            modified_string[i] ='';
        }
    }

    std::cout << modified_string << std::endl;

    return 0;
}

