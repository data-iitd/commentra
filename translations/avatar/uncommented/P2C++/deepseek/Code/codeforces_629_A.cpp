#include <iostream>
#include <vector>
#include <string>

int main() {
    int n;
    std::cin >> n;
    std::vector<std::string> cake;
    int happiness = 0;
    int chocCount = 0;
    int nfat = 1;

    for (int i = 0; i < n; ++i) {
        std::string line;
        std::cin >> line;
        cake.push_back(line);
        for (char j : line) {
            if (j == 'C') {
                chocCount += 1;
            }
        }
        if (chocCount > 1) {
            for (int i = chocCount; i > chocCount - 2; --i) {
                nfat *= i;
            }
            happiness += nfat / 2;
        }
        nfat = 1;
        chocCount = 0;
    }

    for (int j = 0; j < n; ++j) {
        for (int i = 0; i < n; ++i) {
            if (cake[i][j] == 'C') {
                chocCount += 1;
            }
        }
        if (chocCount > 1) {
            for (int i = chocCount; i > chocCount - 2; --i) {
                nfat *= i;
            }
            happiness += nfat / 2;
        }
        nfat = 1;
        chocCount = 0;
    }

    std::cout << happiness << std::endl;
    return 0;
}

