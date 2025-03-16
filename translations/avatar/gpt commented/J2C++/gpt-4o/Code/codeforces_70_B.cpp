#include <iostream>
#include <sstream>
#include <vector>

int main() {
    // Read the maximum allowed length of messages
    int n;
    std::cin >> n;
    std::cin.ignore(); // Ignore the newline character after the integer input

    // Read the input string containing messages
    std::string input;
    std::getline(std::cin, input);

    // Initialize variables to track the maximum message length and store lengths of individual messages
    int max = -1;
    std::vector<int> msgLength;
    int count = 0;

    // Iterate through each character in the input string
    for (size_t i = 0; i < input.length(); i++) {
        char c = input[i];

        // Check if the character is a message delimiter (., ?, or !)
        if (c == '.' || c == '?' || c == '!') {
            // Store the length of the current message and update the maximum length if necessary
            msgLength.push_back(count + 1);
            if (count + 1 > max) max = count + 1;

            // Move to the next character after the delimiter
            count = 0; // Reset count for the next message
        } else {
            // Increment the count for the current message length
            count++;
        }
    }

    // Check if the maximum message length exceeds the allowed length
    if (max > n) {
        std::cout << "Impossible" << std::endl;
    } else {
        // Calculate the number of messages that can fit within the allowed length
        int ans = 0;
        for (size_t i = 0; i < msgLength.size(); i++) {
            int l = msgLength[i];

            // Combine consecutive messages if they fit within the allowed length
            while (i < msgLength.size() - 1 && l + msgLength[i + 1] + 1 <= n) {
                l += msgLength[i + 1] + 1;
                i++;
            }
            ans++; // Increment the count of messages
        }
        // Output the total number of messages that can be sent
        std::cout << ans << std::endl;
    }

    return 0;
}
// <END-OF-CODE>
