

#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;  // Read the input string

    int num_g = 0, num_p = 0;  // Initialize counters for 'g' and 'p' characters
    int score = 0;  // Initialize the score variable to 0

    // Iterate over each character in the string
    for (char x : s) {
        if (x == 'g') {
            // Check if the number of 'g' characters exceeds the number of 'p' characters
            if (num_g - num_p > 0) {
                score += 1;  // Increment the score and the count of 'p' characters
                num_p += 1;
            } else {
                score = score;  // Keep the score unchanged and increment the count of 'g' characters
                num_g += 1;
            }
        } else if (x == 'p') {
            // Check if the number of 'g' characters exceeds the number of 'p' characters
            if (num_g - num_p > 0) {
                score = score;  // Keep the score unchanged and increment the count of 'p' characters
                num_p += 1;
            } else {
                score -= 1;  // Decrement the score and increment the count of 'g' characters
                num_g += 1;
            }
        }
    }

    cout << score << endl;  // Print the final score

    return 0;
}

