#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>

int main() {
    std::string S;
    std::cin >> S;

    std::unordered_set<char> Sa(S.begin(), S.end());

    if (Sa.size() != 2) {
        std::cout << "No" << std::endl;
        return 0;
    }

    std::unordered_map<char, int> c;
    for (char i : Sa) {
        c[i] = 0;
    }

    for (char i : S) {
        c[i]++;
    }

    for (const auto& pair : c) {
        if (pair.second != 2) {
            std::cout << "No" << std::endl;
            return 0;
        }
    }

    std::cout << "Yes" << std::endl;
    return 0;
}
