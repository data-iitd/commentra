#include <iostream>
#include <vector>

int main() {
    // Read input and convert it into a vector of characters
    std::string input;
    std::cin >> input;
    std::vector<char> s(input.begin(), input.end());

    // Initialize counters for 'g' and 'p' occurrences, and the score
    int num_g = 0, num_p = 0;
    int score = 0;

    // Iterate through each character in the input vector
    for (char x : s) {
        // Check if the character is 'g'
        if (x == 'g') {
            // If there are more 'g's than 'p's, increase the score and count 'p'
            if (num_g - num_p > 0) {
                score += 1;  // Increase score for 'g'
                num_p += 1;  // Increment the count of 'p's
            } else {
                // If not, just increment the count of 'g's
                num_g += 1;  // Increment the count of 'g's
            }
        }
        // Check if the character is 'p'
        else if (x == 'p') {
            // If there are more 'g's than 'p's, just count 'p'
            if (num_g - num_p > 0) {
                num_p += 1;  // Increment the count of 'p's
            } else {
                // If not, decrease the score and increment the count of 'g's
                score -= 1;  // Decrease score for 'p'
                num_g += 1;  // Increment the count of 'g's
            }
        }
    }

    // Print the final score
    std::cout << score << std::endl;

    return 0;
}

// <END-OF-CODE>
