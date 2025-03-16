

#include <iostream>
#include <string>

int main() {
    std::string s;
    std::cin >> s;  // Take a string input from the user
    std::string my_str = "";  // Initialize an empty string to build the result

    // Iterate over each character in the input string `s`
    for (char c : s) {
        if (c == '0' || c == '1') {  // Check if the character is '0' or '1'
            my_str += c;  // Append the character to `my_str`
        } else if (c == 'B' &&!my_str.empty()) {  // Check if the character is 'B' and `my_str` is not empty
            my_str.pop_back();  // Remove the last character from `my_str`
        }
    }

    std::cout << my_str << std::endl;  // Print the content of `my_str`

    return 0;
}
