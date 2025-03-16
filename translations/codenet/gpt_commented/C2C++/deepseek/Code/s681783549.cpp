#include <iostream>
#include <string>

int main() {
    // Declare an integer variable for iteration and a string to store input
    int i;
    std::string S;

    // Read a string input from the user
    std::cin >> S;

    // Iterate through each character in the string until the null terminator is reached
    for(i = 0; i < S.length(); i++) {
        // Check if the current character is 'A' and the next character is 'C'
        if(S[i] == 'A' && S[i + 1] == 'C') {
            // If the condition is met, print "Yes" and exit the program
            std::cout << "Yes" << std::endl;
            return 0;
        }
    }

    // If the loop completes without finding "AC", print "No"
    std::cout << "No" << std::endl;
    return 0;
}
