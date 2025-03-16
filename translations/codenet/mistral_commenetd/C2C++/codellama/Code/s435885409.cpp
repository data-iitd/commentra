#include <iostream>
#include <string>

// Function to calculate the score for each inning
int calc_score() {
    int out = 0; // Initialize the number of outs to 0
    std::string str; // Create a string to store the input string
    int score = 0; // Initialize the score to 0
    int base = 0; // Initialize the number of bases to 0

    // Loop through the three events in each inning
    while (out < 3) {
        std::cout << "Enter the event for this at bat (HIT, HOMERUN or OUT): "; // Ask for the event
        std::cin >> str; // Read the event from the standard input

        // Check if the event is OUT
        if (str == "OUT") {
            out++; // Increment the number of outs
        }
        // Check if the event is HIT
        else if (str == "HIT") {
            // If there are already three bases, increment the score
            if (base == 3) {
                score++;
            }
            // If not, increment the number of bases
            else {
                base++;
            }
        }
        // Check if the event is HOMERUN
        else if (str == "HOMERUN") {
            score += (base + 1); // Add the number of bases and 1 to the score
            base = 0; // Reset the number of bases to 0
        }
    }

    // Return the score for this inning
    return score;
}

// Main function to read the number of innings and call calc_score() for each inning
int main() {
    int n; // Initialize the number of innings to be read
    int inning = 0; // Initialize the current inning number to 0

    // Read the number of innings from the standard input
    std::cout << "Enter the number of innings: ";
    std::cin >> n;

    // Loop through each inning and call calc_score() to calculate the score
    while (inning < n) {
        int score = calc_score(); // Call calc_score() to calculate the score for this inning
        std::cout << score << std::endl; // Print the score for this inning
        inning++; // Increment the current inning number
    }

    // Return 0 to indicate successful execution
    return 0;
}

