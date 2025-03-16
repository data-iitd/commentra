#include <iostream>
#include <vector>
#include <string>

int main() {
    std::vector<std::vector<char>> t(4, std::vector<char>(4));
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            std::cin >> t[i][j];
        }
    }

    int black = 0, white = 0, correct = 0;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            black = 0, white = 0;
            for (int x = 0; x < 2; ++x) {
                for (int y = 0; y < 2; ++y) {
                    if (t[i + x][j + y] == '#') {
                        ++black;
                    } else {
                        ++white;
                    }
                }
            }
            if (black == 0 || black == 3 || white == 0 || white == 3 || white == 4 || black == 4) {
                correct = 1;
                break;
            }
        }
        if (correct == 1) {
            break;
        }
    }

    if (correct == 1) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }

    return 0;
}

