#include <iostream>
#include <vector>
#include <string>

int main() {
    int n;
    std::cin >> n;
    std::vector<std::string> cake(n);
    int happiness = 0;
    int chocCount = 0;
    int nfat = 1;

    for (int i = 0; i < n; ++i) {
        std::string line;
        std::cin >> line;
        cake[i] = line;

        for (char j : line) {
            if (j == 'C') {
                ++chocCount;
            }
        }

        if (chocCount > 1) {
            nfat = 1;
            for (int i = chocCount; i > chocCount - 2; --i) {
                nfat *= i;
            }
            happiness += nfat / 2;
        }
        chocCount = 0;
    }

    for (int j = 0; j < n; ++j) {
        for (int i = 0; i < n; ++i) {
            if (cake[i][j] == 'C') {
                ++chocCount;
            }
        }

        if (chocCount > 1) {
            nfat = 1;
            for (int i = chocCount; i > chocCount - 2; --i) {
                nfat *= i;
            }
            happiness += nfat / 2;
        }
        chocCount = 0;
    }

    std::cout << happiness << std::endl;
    return 0;
}
