#include <iostream>
#include <vector>
#include <set>
#include <string>

int main() {
    int n;
    std::cin >> n;

    std::vector<std::string> s(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> s[i];
    }

    std::vector<char> d1, d2;  // Primary and secondary diagonals
    std::set<char> rem;        // Non-diagonal elements

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j) {
                d1.push_back(s[i][j]);
            }
            if (i == n - j - 1) {
                d2.push_back(s[i][j]);
            }
            if (i != j && i != n - j - 1) {
                rem.insert(s[i][j]);
            }
        }
    }

    if (rem.size() != 1) {
        std::cout << "NO" << std::endl;
    } else if (d1 != d2) {
        std::cout << "NO" << std::endl;
    } else if (std::set<char>(d1.begin(), d1.end()).size() != 1) {
        std::cout << "NO" << std::endl;
    } else if (*rem.begin() == *d1.begin()) {
        std::cout << "NO" << std::endl;
    } else {
        std::cout << "YES" << std::endl;
    }

    return 0;
}
