#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <regex>

int main() {
    // Read an integer input which represents the maximum allowed length for sentences
    int n;
    std::cin >> n;
    std::cin.ignore(); // Ignore the newline character after the integer input

    // Initialize the answer counter and the sum of lengths of sentences
    int ans = 1;
    int sumL = 0;

    // Read the input text
    std::string inputText;
    std::getline(std::cin, inputText);

    // Split the input text into sentences based on punctuation marks (., ?, !)
    std::regex re("[.?!]");
    std::sregex_token_iterator it(inputText.begin(), inputText.end(), re, -1);
    std::sregex_token_iterator end;

    for (; it != end; ++it) {
        std::string s = it->str();
        s = std::regex_replace(s, std::regex("^\\s+|\\s+$"), ""); // Strip whitespace
        s += '.'; // Add a period to the end of the sentence
        int L = s.length(); // Calculate the length of the current sentence

        // Check if the length of the sentence is greater than 1 (to avoid empty sentences)
        if (L > 1) {
            // If the length of the sentence exceeds the maximum allowed length, print "Impossible" and exit
            if (L > n) {
                std::cout << "Impossible" << std::endl;
                return 0;
            }

            // Check if adding the current sentence length to the sum exceeds the maximum allowed length
            if (sumL + L + (sumL > 0) > n) {
                ans++; // Increment the answer counter for a new line
                sumL = L; // Reset the sum of lengths to the current sentence length
            } else {
                // Update the sum of lengths by adding the current sentence length
                sumL = sumL + L + (sumL > 0); // Add 1 if there was a previous sentence (to account for space)
            }
        }
    }

    // Print the total number of lines needed
    std::cout << ans << std::endl;

    return 0;
}

// <END-OF-CODE>
