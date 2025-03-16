
#include <iostream>
#include <string>
#include <vector>

int main() {
    std::string s;  // Declare a string variable to store the input string
    std::vector<char> res;  // Declare a vector of characters to store the result
    std::string punctuation = ",.!?";  // Define a string of punctuation marks

    std::cout << "Enter a string: ";  // Prompt the user to enter a string
    std::getline(std::cin, s);  // Read the input string from the user

    // Iterate over each character in the input string
    for (int i = 0; i < s.length(); i++) {
        if (i > 0) {  // Check if it's not the first character
            if (s[i] =='') {  // Check if the current character is a space
                if (res[res.size() - 1]!='') {  // Check if the last character in res is not a space
                    res.push_back(s[i]);  // Append the current space to res
                } else {
                    continue;  // Skip the current space if the last character is also a space
                }
            } else {  // If the current character is not a space
                if (punctuation.find(s[i])!= std::string::npos) {  // Check if the current character is a punctuation mark
                    if (res[res.size() - 1] =='') {  // Check if the last character in res is a space
                        res.pop_back();  // Remove the last character (space) from res
                    }
                    res.push_back(s[i]);  // Append the punctuation mark to res
                    res.push_back(' ');  // Append a space after the punctuation mark
                } else {
                    res.push_back(s[i]);  // Append the character to res if it's not a punctuation mark
                }
            }
        } else {  // For the first character
            if (s[i] =='') {  // Check if the first character is a space
                continue;  // Skip the first space
            }
            if (punctuation.find(s[i])!= std::string::npos) {  // Check if the first character is a punctuation mark
                continue;  // Skip the first punctuation mark
            } else {
                res.push_back(s[i]);  // Append the first character to res
            }
        }
    }

    // Join the vector res into a string and print it
    std::string result = "";
    for (char c : res) {
        result += c;
    }
    std::cout << result << std::endl;

    return 0;
}
