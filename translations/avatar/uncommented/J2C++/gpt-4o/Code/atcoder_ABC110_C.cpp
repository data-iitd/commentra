#include <iostream>
#include <string>
#include <vector>

int main() {
    std::string S, T;
    std::getline(std::cin, S);
    std::getline(std::cin, T);

    std::vector<std::string> A = { "a", "b", "c", "d", "e", "f", "g", "h", "i", "j", 
                                   "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", 
                                   "u", "v", "w", "x", "y", "z" };

    bool res = true;

    for (const std::string& s : A) {
        size_t sIdx = S.find(s);
        if (sIdx == std::string::npos) continue;

        char t = T[sIdx];
        size_t idx = 0;

        while (idx < S.length()) {
            size_t foundS = S.find(s, idx);
            size_t foundT = T.find(t, idx);

            if (foundS != std::string::npos) {
                if (foundS != foundT) {
                    res = false;
                    break;
                } else {
                    idx = foundS + 1;
                }
            } else if (foundT != std::string::npos) {
                res = false;
                break;
            } else {
                break;
            }
        }

        if (!res) break;
    }

    if (res) std::cout << "Yes" << std::endl;
    else std::cout << "No" << std::endl;

    return 0;
}

// <END-OF-CODE>
