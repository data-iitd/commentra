#include <iostream>
#include <vector>
#include <string>

int main() {
    int n;
    std::cin >> n;

    std::string s, t;
    std::cin >> s >> t;

    if (s == t) {
        std::cout << n << std::endl;
    } else {
        int cnt = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n - i; ++j) {
                if (s[i + j] != t[j]) {
                    break;
                }

                if (j == n - i - 1) {
                    cnt = n - i;
                }
            }
        }

        std::cout << 2 * n - cnt << std::endl;
    }

    return 0;
}

