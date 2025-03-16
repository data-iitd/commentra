#include <iostream> // For input and output operations
#include <sstream> // For string stream operations
#include <string> // For string operations
#include <vector> // For using vectors
#include <stdexcept> // For exception handling

// The Main class is defined to run the program
int main() {
    std::ios::sync_with_stdio(false); // Disable synchronization with C I/O for faster input/output
    std::cin.tie(nullptr); // Untie cin from cout for faster input

    std::string S; // Declare a string to hold the input
    std::cin >> S; // Read the input string
    int score = 0; // Initialize the score to 0

    // Iterate through each character in the string S
    for (size_t i = 0; i < S.length(); i++) {
        char my = (i % 2 == 0) ? 'g' : 'p'; // Determine the expected character based on the index
        char his = S[i]; // Get the character at the current index in S
        // Compare the expected character with the actual character and update the score
        if (my != his) {
            score += (my == 'p') ? 1 : -1; // Update the score based on the expected character
        }
    }
    std::cout << score << std::endl; // Print the final score

    return 0; // Return 0 to indicate successful execution
}

// <END-OF-CODE>
