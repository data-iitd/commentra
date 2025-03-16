#include <iostream>
#include <string>

int main() {
    int K;
    std::string S;

    // Read the integer K from the standard input
    std::cin >> K;

    // Read a string S from the standard input
    std::cin >> S;

    // Check if the length of the string S is less than or equal to K
    if (S.length() <= K) {
        // If the condition is true, print the string S
        std::cout << S << std::endl;
    } else {
        // If the condition is false, print a slice of the string S
        // from the beginning to the index K, followed by three dots '...'
        std::cout << S.substr(0, K) + "..." << std::endl;
    }

    return 0;
}

