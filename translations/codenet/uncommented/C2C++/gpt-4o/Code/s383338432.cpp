#include <iostream>
#include <string>

int main() {
    int height, width;
    std::cin >> height >> width;
    std::string input_str;

    for(int i = 0; i < width + 2; i++) {
        std::cout << "#";
    }
    std::cout << std::endl;

    for(int i = 0; i < height; i++) {
        std::cin >> input_str;
        std::cout << "#" << input_str << "#" << std::endl;
    }

    for(int i = 0; i < width + 2; i++) {
        std::cout << "#";
    }
    std::cout << std::endl;

    return 0;
}

// <END-OF-CODE>
