#include <iostream>
#include <vector>
#include <string>

int main() {
    std::string s;  // Declare a string to store user input
    std::getline(std::cin, s);  // Take input string from user
    std::vector<char> res;  // Initialize an empty vector to store the result
    std::vector<char> punctuation = {',', '.', '!', '?'};  // Define a vector of punctuation marks

    // Iterate over each character in the input string
    for (size_t i = 0; i < s.length(); ++i) {
        if (i >= 1) {  // Check if it's not the first character
            if (s[i] == ' ') {  // Check if the current character is a space
                if (res.empty() || res.back() != ' ') {  // Check if res is empty or last character is not a space
                    res.push_back(s[i]);  // Append the current space to res
                }
            } else {  // If the current character is not a space
                if (std::find(punctuation.begin(), punctuation.end(), s[i]) != punctuation.end()) {  // Check if the current character is a punctuation mark
                    if (!res.empty() && res.back() == ' ') {  // Check if the last character in res is a space
                        res.pop_back();  // Remove the last character (space) from res
                    }
                    res.push_back(s[i]);  // Append the punctuation mark to res
                    res.push_back(' ');  // Append a space after the punctuation mark
                } else {
                    res.push_back(s[i]);  // Append the character to res if it's not a punctuation mark
                }
            }
        } else {  // For the first character
            if (s[i] == ' ') {  // Check if the first character is a space
                continue;  // Skip the first space
            }
            if (std::find(punctuation.begin(), punctuation.end(), s[i]) != punctuation.end()) {  // Check if the first character is a punctuation mark
                continue;  // Skip the first punctuation mark
            } else {
                res.push_back(s[i]);  // Append the first character to res
            }
        }
    }

    // Join the vector res into a string and print it
    std::string result(res.begin(), res.end());
    std::cout << result;

    return 0;
}

// <END-OF-CODE>
