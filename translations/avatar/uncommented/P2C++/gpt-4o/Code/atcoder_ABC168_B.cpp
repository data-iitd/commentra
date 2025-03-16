#include <iostream>
#include <string>

std::string mainFunction() {
    int K;
    std::cin >> K;
    std::string S;
    std::cin >> S;

    if (S.length() <= K) {
        return S;
    }
    return S.substr(0, K) + "...";
}

int main() {
    std::cout << mainFunction() << std::endl;
    return 0;
}

// <END-OF-CODE>
