#include <iostream>
#include <cstring>

int main() {
    int sum = 0;
    char x[1002];

    while (true) {
        std::cin >> x;
        if (x[0] == '0') {
            break;
        }

        sum = 0;
        for (int i = 0; i < 1002; i++) {
            if (x[i] == '\0') {
                std::cout << sum << std::endl;
                break;
            } else {
                sum += x[i] - '0';
            }
        }
    }

    return 0;
}

// <END-OF-CODE>
