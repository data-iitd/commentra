#include <iostream>
#include <string>

int main()
{
    std::string user_input;
    std::getline(std::cin, user_input);

    std::string modified_input = user_input;
    modified_input.replace(",", " ");

    std::cout << modified_input << std::endl;

    return 0;
}
