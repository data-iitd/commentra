#include <iostream>
#include <string>

using namespace std;

int main() {
    // Initialize an empty string to store input characters
    string s;

    // Get input from user
    cin >> s;

    // Initialize counters for 'g' and 'p' symbols
    int num_g = 0, num_p = 0;

    // Initialize score variable
    int score = 0;

    // Iterate through each character in the string's'
    for (int i = 0; i < s.length(); i++) {

        // Check if current character is 'g'
        if (s[i] == 'g') {

            // Check if number of 'g' symbols is greater than number of 'p' symbols
            if (num_g - num_p > 0) {

                // Increment score and number of 'p' symbols
                score += 1;
                num_p += 1;

                // Comment: If there are more 'g' symbols than 'p' symbols, increment score and update number of 'p' symbols

            } else {

                // Do not change score and increment number of 'g' symbols
                score = score;
                num_g += 1;

                // Comment: If there are less or equal 'g' symbols than 'p' symbols, do not change score and update number of 'g' symbols

        } else if (s[i] == 'p') {

            // Check if number of 'g' symbols is greater than number of 'p' symbols
            if (num_g - num_p > 0) {

                // Do not change score and increment number of 'p' symbols
                score = score;
                num_p += 1;

                // Comment: If there are more 'g' symbols than 'p' symbols, do not change score and update number of 'p' symbols

            } else {

                // Decrement score and increment number of 'g' symbols
                score -= 1;
                num_g += 1;

                // Comment: If there are less or equal 'g' symbols than 'p' symbols, decrement score and update number of 'g' symbols

    }

    // Print the final score
    cout << score << endl;

    // Comment: After iterating through all characters in the string's', print the final score

    return 0;
}

