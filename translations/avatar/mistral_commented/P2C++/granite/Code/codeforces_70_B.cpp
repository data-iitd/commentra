
#include <iostream>
#include <regex>

int main() {
    // Taking the number of sentences n as input
    int n;
    std::cin >> n;

    // Initializing the answer counter ans and the sum of lengths of sentences sumL
    int ans = 1, sumL = 0;

    // Regular expression pattern to split the input string into sentences
    std::regex pattern("[.?!]");

    // Taking the input string as input
    std::string input;
    std::getline(std::cin, input);

    // Loop to split the input string into sentences based on punctuation marks
    for (auto s : std::sregex_token_iterator(input.begin(), input.end(), pattern, -1)) {
        // Stripping leading and trailing whitespaces from the sentence s
        std::string sTrimmed = s.trim();
        // Adding a dot at the end of the sentence if it doesn't already have one
        sTrimmed += '.';

        // Calculating the length L of the sentence s
        int L = sTrimmed.length();

        // Checking if the length of the sentence is greater than the number of sentences n
        if (L > n) {
            // Printing an error message and exiting the program if the condition is true
            std::cout << "Impossible" << std::endl;
            return 0;
        }

        // Checking if the sum of lengths of all previous sentences and the current sentence is greater than n
        if (sumL + L + (sumL > 0)) {
            // Incrementing the answer counter ans if the condition is true
            ans += 1;
            // Updating the sum of lengths sumL with the length of the current sentence
            sumL = L;
        } else {
            // Updating the sum of lengths sumL with the length of the current sentence and the previous sentence's length if any
            sumL = sumL + L + (sumL > 0);
        }
    }

    // Printing the final answer
    std::cout << ans << std::endl;

    return 0;
}
