#include <iostream>
#include <string>

int main() {
    // Get user input
    std::string ip;
    std::cin >> ip;

    // Initialize an empty string to store the transformed number
    std::string st = "";

    // Check if the input length is not equal to 1
    if (ip.length() != 1) {
        // If the first character is '9', keep it and remove it from the input
        if (ip[0] == '9') {
            st = "9";  // Start the output string with '9'
            ip = ip.substr(1);  // Remove the first character from the input
        }

        // Iterate through each character in the remaining input
        for (char i : ip) {
            // If the digit is greater than 4, calculate its complement to 9
            if (i > '4') {
                int n = 9 - (i - '0');  // Calculate the complement
                st += std::to_string(n);  // Append the complement to the output string
            } else {
                // If the digit is 4 or less, keep it unchanged
                st += i;  // Append the original digit to the output string
            }
        }
    } else {
        // If the input length is 1, simply assign it to the output
        st = ip;
    }

    // Print the final transformed number as an integer
    std::cout << std::stoi(st) << std::endl;

    return 0;
}

// <END-OF-CODE>
