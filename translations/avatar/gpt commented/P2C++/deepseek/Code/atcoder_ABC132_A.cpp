#include <iostream>
#include <string>
#include <unordered_set>
#include <map>

int main() {
    std::string S;
    std::cin >> S;

    std::map<char, int> c;
    for (char ch : S) {
        c[ch]++;
    }

    std::unordered_set<char> Sa(S.begin(), S.end());

    if (Sa.size() != 2) {
        std::cout << "No" << std::endl;
        return 0;
    }

    for (char ch : Sa) {
        if (c[ch] != 2) {
            std::cout << "No" << std::endl;
            return 0;
        }
    }

    std::cout << "Yes" << std::endl;
    return 0;
}
