#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <algorithm>

int main() {
    std::string input;
    std::getline(std::cin, input);
    int N = input.size();
    std::unordered_set<std::string> set;
    int K;
    std::cin >> K;
    std::cin.ignore(); // To ignore the newline character after K
    int res = 0;

    for (int k = 0; k < K; ++k) {
        std::string pattern;
        std::getline(std::cin, pattern);
        int a = 0, b = 0;
        for (int i = 0; i < N; ++i) {
            if (input[i] == pattern[0]) {
                ++a;
            } else if (input[i] == pattern[1]) {
                ++b;
            } else {
                res += std::min(a, b);
                a = b = 0;
            }
        }
        res += std::min(a, b);
    }

    std::cout << res << std::endl;
    return 0;
}
