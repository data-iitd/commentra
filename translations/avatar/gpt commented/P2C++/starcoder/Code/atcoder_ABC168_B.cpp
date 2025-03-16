#include <iostream>
#include <string>

int main() {
    // Read an integer input K from the user
    int K;
    std::cin >> K;
    
    // Read a string input S from the user
    std::string S;
    std::cin >> S;
    
    // Check if the length of the string S is less than or equal to K
    if (S.length() <= K) {
        // If true, return the original string S
        return S;
    }
    
    // If the length of S is greater than K, return the first K characters followed by '...'
    return S.substr(0, K) + "...";
}

// 