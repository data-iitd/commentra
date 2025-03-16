#include <iostream>
#include <string>
#include <sstream>

int main() {
    long a;
    std::cin >> a;

    std::string b;
    std::cin >> b;

    std::string bStr = "";
    for (char c : b) {
        if (c != '.') {
            bStr += c;
        }
    }

    int bInt;
    std::stringstream ss(bStr);
    ss >> bInt;

    long result = (a * bInt) / 100;

    std::cout << result << std::endl;

    return 0;
}

