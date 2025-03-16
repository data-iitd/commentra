#include <iostream>
#include <string>

int main() {
    int K;
    std::string S;

    // Read an integer input K from the user
    std::cin >> K;
    
    // Read a string input S from the user
    std::cin >> S;
    
    // Check if the length of the string S is less than or equal to K
    if (S.length() <= K) {
        // If true, return the original string S
        std::cout << S << std::endl;
    } else {
        // If the length of S is greater than K, return the first K characters followed by '...'
        std::cout << S.substr(0, K) + "..." << std::endl;
    }

    return 0;
}

