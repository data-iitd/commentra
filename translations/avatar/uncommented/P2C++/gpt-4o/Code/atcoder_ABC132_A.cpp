#include <iostream>
#include <unordered_map>
#include <set>
#include <string>

int main() {
    std::string S;
    std::cin >> S;

    std::unordered_map<char, int> c;
    for (char ch : S) {
        c[ch]++;
    }

    std::set<char> Sa(S.begin(), S.end());

    if (Sa.size() != 2) {
        std::cout << "No" << std::endl;
        return 0;
    }

    for (char i : Sa) {
        if (c[i] != 2) {
            std::cout << "No" << std::endl;
            return 0;
        }
    }

    std::cout << "Yes" << std::endl;
    return 0;
}

// <END-OF-CODE>
