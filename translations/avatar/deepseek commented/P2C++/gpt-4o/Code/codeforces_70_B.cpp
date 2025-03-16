#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <regex>

int main() {
    // Take the maximum sentence length as input
    int n;
    std::cin >> n;
    std::cin.ignore(); // To ignore the newline character after the integer input

    // Initialize variables to keep track of the number of sentences and their cumulative length
    int ans = 1;
    int sumL = 0;

    // Take a string input
    std::string input;
    std::getline(std::cin, input);

    // Use regex to split the input into sentences using [.?!]
    std::regex re("[.?!]");
    std::sregex_token_iterator it(input.begin(), input.end(), re, -1);
    std::sregex_token_iterator reg_end;

    for (; it != reg_end; ++it) {
        std::string s = it->str();
        // Strip leading and trailing whitespace and add a period to the end of the sentence
        s = std::regex_replace(s, std::regex("^\\s+|\\s+$"), ""); // Trim whitespace
        s += '.';
        
        // Calculate the length of the sentence
        int L = s.length();
        
        // Check if the sentence length is greater than 1
        if (L > 1) {
            // Check if the sentence length is greater than the maximum allowed length
            if (L > n) {
                // If the sentence is too long, print "Impossible" and exit
                std::cout << "Impossible" << std::endl;
                return 0;
            }
            
            // Check if adding the current sentence would exceed the maximum allowed length
            if (sumL + L + (sumL > 0) > n) {
                // If adding the sentence would exceed the maximum length, increment the sentence count
                ans++;
                // Reset the cumulative length to the length of the current sentence
                sumL = L;
            } else {
                // Otherwise, add the length of the current sentence to the cumulative length
                sumL += L + (sumL > 0);
            }
        }
    }

    // Print the total number of sentences
    std::cout << ans << std::endl;

    return 0;
}

// <END-OF-CODE>
