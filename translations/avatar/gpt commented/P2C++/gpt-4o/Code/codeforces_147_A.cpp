#include <iostream>
#include <vector>
#include <string>

int main() {
    // Take input from the user
    std::string s;
    std::getline(std::cin, s);

    // Initialize an empty vector to store the result
    std::vector<char> res;

    // Define a list of punctuation marks to check against
    std::string punctuation = ",.!?";

    // Iterate through each character in the input string
    for (size_t i = 0; i < s.length(); ++i) {
        // Check if the current index is greater than or equal to 1
        if (i >= 1) {
            // If the current character is a space
            if (s[i] == ' ') {
                // Only append a space if the last element in res is not a space
                if (res.empty() || res.back() != ' ') {
                    res.push_back(' ');
                }
            } else {
                // If the current character is a punctuation mark
                if (punctuation.find(s[i]) != std::string::npos) {
                    // If the last element in res is a space, remove it
                    if (!res.empty() && res.back() == ' ') {
                        res.pop_back();
                    }
                    // Append the punctuation mark to the result
                    res.push_back(s[i]);
                    // Append a space after the punctuation
                    res.push_back(' ');
                } else {
                    // If the current character is not punctuation, append it to the result
                    res.push_back(s[i]);
                }
            }
        } else {
            // For the first character, handle it separately
            if (s[i] != ' ' && punctuation.find(s[i]) == std::string::npos) {
                // Append the first character to the result if it's not a space or punctuation
                res.push_back(s[i]);
            }
        }
    }

    // Join the vector into a single string and print the result
    std::string result(res.begin(), res.end());
    std::cout << result;

    return 0;
}

// <END-OF-CODE>
