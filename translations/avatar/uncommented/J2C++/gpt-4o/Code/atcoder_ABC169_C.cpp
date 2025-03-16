#include <iostream>
#include <string>

int main() {
    long a;
    std::string b;
    std::cin >> a >> b;

    std::string bStr;
    for (char c : b) {
        if (c != '.') {
            bStr += c;
        }
    }

    int bInt = std::stoi(bStr);
    long result = (a * bInt) / 100;
    std::cout << result << std::endl;

    return 0;
}

// <END-OF-CODE>
