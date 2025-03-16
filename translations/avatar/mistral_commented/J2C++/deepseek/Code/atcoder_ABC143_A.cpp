#include <iostream>
#include <string>
#include <sstream>

int main() {
    try {
        std::string line;
        std::getline(std::cin, line);
        std::istringstream iss(line);
        int a, b;
        char space;

        iss >> a >> space >> b;

        int c = a - b * 2;

        if (c < 0) {
            c = 0;
        }

        std::cout << c << std::endl;
    } catch (...) {
        // Handle any exceptions that might occur during the execution of the program
    }

    return 0;
}
