
#include <iostream>
#include <string>

int main() {
    std::string input;
    std::getline(std::cin, input);
    std::string output = input.replace(input.find(","), 1, " ");
    std::cout << output << std::endl;
    return 0;
}
// 