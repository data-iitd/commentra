#include <iostream>
#include <vector>
#include <string>

int main() {
    int n;
    std::cin >> n;
    std::string number_str;
    std::cin >> number_str;

    int h1 = 0, h2 = 0, x = 0;
    std::vector<int> number(n);

    for (int i = 0; i < n; ++i) {
        number[i] = number_str[i] - '0';
    }

    for (int i = 0; i < n; ++i) {
        if (number[i] != 4 && number[i] != 7) {
            std::cout << "NO" << std::endl;
            x = 1;
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
