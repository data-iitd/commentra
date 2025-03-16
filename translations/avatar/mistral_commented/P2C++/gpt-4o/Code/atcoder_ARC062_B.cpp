#include <iostream>
#include <vector>

int main() {
    // Initialize an empty vector to store input characters
    std::vector<char> s;
    char ch;

    // Read input characters until newline
    while (std::cin.get(ch) && ch != '\n') {
        s.push_back(ch);
    }

    // Initialize counters for 'g' and 'p' symbols
    int num_g = 0, num_p = 0;

    // Initialize score variable
    int score = 0;

    // Iterate through each character in the vector 's'
    for (char x : s) {
        // Check if current character is 'g'
        if (x == 'g') {
            // Check if number of 'g' symbols is greater than number of 'p' symbols
            if (num_g - num_p > 0) {
                // Increment score and number of 'p' symbols
                score += 1;
                num_p += 1;
                // Comment: If there are more 'g' symbols than 'p' symbols, increment score and update number of 'p' symbols
            } else {
                // Do not change score and increment number of 'g' symbols
                num_g += 1;
                // Comment: If there are less or equal 'g' symbols than 'p' symbols, do not change score and update number of 'g' symbols
            }
        }
        // Check if current character is 'p'
        else if (x == 'p') {
            // Check if number of 'g' symbols is greater than number of 'p' symbols
            if (num_g - num_p > 0) {
                // Do not change score and increment number of 'p' symbols
                num_p += 1;
                // Comment: If there are more 'g' symbols than 'p' symbols, do not change score and update number of 'p' symbols
            } else {
                // Decrement score and increment number of 'g' symbols
                score -= 1;
                num_g += 1;
                // Comment: If there are less or equal 'g' symbols than 'p' symbols, decrement score and update number of 'g' symbols
            }
        }
    }

    // Print the final score
    std::cout << score << std::endl;
    // Comment: After iterating through all characters in the vector 's', print the final score

    return 0;
}

// <END-OF-CODE>
