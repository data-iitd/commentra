#include <iostream>
#include <vector>
#include <sstream>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> number(n);
    std::string line;
    std::getline(std::cin, line); // Read the newline character
    std::getline(std::cin, line);
    std::stringstream ss(line);

    for (int i = 0; i < n; ++i) {
        ss >> number[i];
    }

    int h1 = 0, h2 = 0;
    bool x = false;

    for (int i = 0; i < n; ++i) {
        if (number[i] != 4 && number[i] != 7) {
            std::cout << "NO" << std::endl;
            x = true;
            break;
        }

        if (i < n / 2) {
            h1 += number[i];
        } else {
            h2 += number[i];
        }
    }

    if (!x) {
        if (h1 == h2) {
            std::cout << "YES" << std::endl;
        } else {
            std::cout << "NO" << std::endl;
        }
    }

    return 0;
}
