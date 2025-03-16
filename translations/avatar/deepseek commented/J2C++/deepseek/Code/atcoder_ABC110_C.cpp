#include <iostream>
#include <string>
#include <vector>

int main() {
    std::string S, T;
    std::cin >> S >> T;

    std::vector<std::string> A = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"};

    bool res = true;

    for (const auto& s : A) {
        size_t sIdx = S.find(s);
        if (sIdx == std::string::npos) continue;

        std::string t = std::string(1, T[sIdx]);

        size_t idx = 0;
        while (idx < S.length()) {
            size_t sPos = S.find(s, idx);
            if (sPos != std::string::npos) {
                if (S.find(s, idx) != T.find(t, idx)) {
                    res = false;
                    break;
                } else {
                    idx = sPos + 1;
                }
            } else if (T.find(t, idx) != std::string::npos) {
                res = false;
                break;
            } else {
                break;
            }
        }
        if (!res) break;
    }

    if (res) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }

    return 0;
}
