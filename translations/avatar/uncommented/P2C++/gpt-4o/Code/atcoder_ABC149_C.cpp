#include <iostream>
#include <vector>

int main() {
    int X;
    std::cin >> X;
    std::vector<bool> prime(100010, true);
    prime[0] = false;
    prime[1] = false;

    for (int i = 4; i < 100010; i += 2) {
        prime[i] = false;
    }

    for (int i = 3; i * i <= 100008; i += 2) {
        if (prime[i]) {
            for (int j = i + i; j < 100008; j += i) {
                prime[j] = false;
            }
        }
    }

    for (int i = X; i < 100008; ++i) {
        if (prime[i]) {
            std::cout << i << std::endl;
            break;
        }
    }

    return 0;
}

// <END-OF-CODE>
