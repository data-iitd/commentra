
#include <iostream>
#include <string>

// Define the main function, taking no arguments
int main() {

    // Read the integer K from the standard input
    int K;
    std::cin >> K;

    // Read a string S from the standard input
    std::string S;
    std::cin >> S;

    // Check if the length of the string S is less than or equal to K
    if (S.size() <= K) {

        // If the condition is true, return the string S
        return 0;
    }

    // If the condition is false, return a slice of the string S
    // from the beginning to the index K, followed by three dots '...'
    std::cout << S.substr(0, K) << "...";

    // Return success
    return 0;
}

