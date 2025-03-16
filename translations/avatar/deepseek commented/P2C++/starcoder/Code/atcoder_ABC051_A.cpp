
#include <iostream>
#include <string>

int main()
{
    std::string input;
    std::getline(std::cin, input);
    std::cout << input.replace(input.find(","), 1, " ");
    return 0;
}

