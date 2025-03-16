

#include <iostream>
#include <string>
#include <cstdlib>

int main() {
    std::string input;
    std::cin >> input;
    int x = std::stoi(input);
    bool bool = x == 1? true : false;
    int result =!bool? 1 : 0;
    std::cout << result << std::endl;
    return 0;
}

