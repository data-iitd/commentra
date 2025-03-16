#include <iostream>
#include <string>
#include <sstream>

int main() {
    std::string line;
    std::getline(std::cin, line);
    std::istringstream iss(line);
    int h, a;
    char space;
    iss >> h >> space >> a;
    int num = 0;

    while (h > 0) {
        h -= a;
        num++;
    }

    std::cout << num << std::endl;
    return 0;
}
