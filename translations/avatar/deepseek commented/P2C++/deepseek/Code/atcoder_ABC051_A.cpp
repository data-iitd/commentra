```cpp
#include <iostream>
#include <vector>
#include <string>

int main() {
    std::vector<std::string> words;
    std::string input;

    while (std::getline(std::cin, input)) {
        if (input == "<END-OF-CODE>")