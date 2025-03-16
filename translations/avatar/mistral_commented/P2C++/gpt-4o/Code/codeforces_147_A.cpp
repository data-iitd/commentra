#include <iostream>
#include <vector>
#include <string>

int main() {
    // Take user input as a string 's'
    std::string s;
    std::getline(std::cin, s);

    // Initialize an empty vector 'res' to store the final result
    std::vector<std::string> res;

    // Define a vector 'punctuation' containing all the punctuation marks
    std::vector<char> punctuation = {',', '.', '!', '?'};

    // Iterate through each character 'i' in the string 's'
    for (size_t i = 0; i < s.length(); i++) {
        // If current character is a space and previous character is not empty,
        // append the space to the result vector
        if (i >= 1) {
            if (s[i] == ' ') {
                if (!res.empty() && res.back() != " ") {
                    // Append space to the result vector
                    res.push_back(" ");
                }
            }
        }

        // If current character is not a space and is a punctuation mark,
        // check if the previous character is empty, if yes then pop the last character from the result vector
        // and append the current punctuation mark along with an empty string
        else if (std::find(punctuation.begin(), punctuation.end(), s[i]) != punctuation.end()) {
            if (!res.empty() && res.back() == " ") {
                res.pop_back();
                res.push_back(std::string(1, s[i]));
                res.push_back(" ");
            } else {
                res.push_back(std::string(1, s[i]));
            }
        }

        // If current character is not a space and is not a punctuation mark,
        // simply append it to the result vector
        else {
            res.push_back(std::string(1, s[i]));
        }
    }

    // Join all the elements of the result vector and print the final string
    std::string result;
    for (const auto& part : res) {
        result += part;
    }
    std::cout << result;

    return 0;
}

// <END-OF-CODE>
