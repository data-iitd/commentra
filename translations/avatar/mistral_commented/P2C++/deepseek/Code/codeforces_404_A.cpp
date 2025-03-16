#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <sstream>

int main() {
    int n;
    std::cin >> n;
    std::cin.ignore(); // To ignore the newline character after the integer input

    std::vector<std::vector<std::string>> s(n, std::vector<std::string>(n));

    for (int i = 0; i < n; ++i) {
        std::string row;
        std::getline(std::cin, row);
        std::stringstream ss(row);
        std::string element;
        std::vector<std::string> k;
        while (ss >> element) {
            k.push_back(element);
        }
        s[i] = k;
    }

    std::set<std::string> rem;
    std::vector<std::string> d1, d2;

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
        return 0;
    }

    if (d1 != d2) {
        std::cout << "NO" << std::endl;
        return 0;
    }

    if (std::set<std::string>(d1.begin(), d1.end()).size() != 1) {
        std::cout << "NO" << std::endl;
        return 0;
    }

    if (std::set<std::string>(d1.begin(), d1.end()) == rem) {
        std::cout << "NO" << std::endl;
        return 0;
    }

    std::cout << "YES" << std::endl;
    return 0;
}

