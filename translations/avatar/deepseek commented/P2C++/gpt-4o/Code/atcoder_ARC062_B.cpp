#include <iostream>
#include <vector>
#include <string>

int main() {
    std::string input;
    std::cin >> input;  // Read the input string
    std::vector<char> s(input.begin(), input.end());  // Convert the input string into a vector of characters
    int num_g = 0, num_p = 0;  // Initialize counters for 'g' and 'p' characters
    int score = 0;  // Initialize the score variable to 0

    // Iterate over each character in the vector
    for (char x : s) {
        if (x == 'g') {
            // Check if the number of 'g' characters exceeds the number of 'p' characters
            if (num_g - num_p > 0) {
                score += 1;  // Increment the score and the count of 'p' characters
                num_p += 1;
            } else {
                // Keep the score unchanged and increment the count of 'g' characters
                num_g += 1;
            }
        } else if (x == 'p') {
            // Check if the number of 'g' characters exceeds the number of 'p' characters
            if (num_g - num_p > 0) {
                // Keep the score unchanged and increment the count of 'p' characters
                num_p += 1;
            } else {
                score -= 1;  // Decrement the score and increment the count of 'g' characters
                num_g += 1;
            }
        }
    }

    std::cout << score << std::endl;  // Print the final score
    return 0;
}  // <END-OF-CODE>
