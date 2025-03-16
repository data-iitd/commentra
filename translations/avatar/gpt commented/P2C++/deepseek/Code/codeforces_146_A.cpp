#include <iostream>
#include <vector>
#include <string>

int main() {
    int n;
    std::cin >> n;

    std::string input;
    std::cin >> input;

    int h1 = 0, h2 = 0, x = 0;

    for (int i = 0; i < n; ++i) {
        int num = input[i] - '0';
        if (num != 4 && num != 7) {
            std::cout << "NO" << std::endl;
            x = 1;
            break;
        }

        if (i < n / 2) {
            h1 += num;
        } else {
            h2 += num;
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
