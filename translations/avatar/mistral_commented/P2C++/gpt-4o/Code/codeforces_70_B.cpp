#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <regex>

int main() {
    // Taking the number of sentences n as input
    int n;
    std::cin >> n;
    std::cin.ignore(); // To ignore the newline character after the integer input

    // Initializing the answer counter ans and the sum of lengths of sentences sumL
    int ans = 1, sumL = 0;

    // Taking the input string
    std::string inputString;
    std::getline(std::cin, inputString);

    // Using regex to split the input string into sentences based on punctuation marks
    std::regex re("[.?!]");
    std::sregex_token_iterator it(inputString.begin(), inputString.end(), re, -1);
    std::sregex_token_iterator reg_end;

    for (; it != reg_end; ++it) {
        // Stripping leading and trailing whitespaces from the sentence
        std::string s = it->str();
        s.erase(0, s.find_first_not_of(" \n\r\t")); // Ltrim
        s.erase(s.find_last_not_of(" \n\r\t") + 1); // Rtrim
        s += '.'; // Adding a dot at the end of the sentence

        // Calculating the length L of the sentence
        int L = s.length();

        // Checking if the length of the sentence is greater than the number of sentences n
        if (L > n) {
            // Printing an error message and exiting the program if the condition is true
            std::cout << "Impossible" << std::endl;
            return 0;
        }

        // Checking if the sum of lengths of all previous sentences and the current sentence is greater than n
        if (sumL + L + (sumL > 0)) {
            // Incrementing the answer counter ans if the condition is true
            ans++;
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

// <END-OF-CODE>
