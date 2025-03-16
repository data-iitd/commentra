#include <iostream>
#include <string>

int main() {
    std::string S;
    std::cin >> S;

    int i = 2;

    while (i <= S.length()) {
        if (S.substr(0, (S.length() - i) / 2) == S.substr((S.length() - i) / 2, S.length() - i)) {
            std::cout << (S.length() - i) << std::endl;
            break;
        }
        i += 2;
    }

    return 0;
}

