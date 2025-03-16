#include <iostream>
#include <string>
using namespace std;

int main() {
    int n; // Maximum length for each message
    string input; // Input text
    cin >> n >> input; // Reading the input

    int max = -1; // Maximum message length
    int msgLength[input.length() / 2]; // Array to store message lengths
    int count = 0; // Counter for current message length
    int idx = 0; // Index for msgLength array

    // Iterating through the input string to determine message lengths
    for (int i = 0; i < input.length(); i++) {
        char c = input[i]; // Getting the current character
        if (c == '.' || c == '?' || c == '!') {
            msgLength[idx++] = ++count; // Storing the length of the current message and incrementing the index
            if (count > max) max = count; // Updating the maximum message length if necessary
            i++; // Skipping the next character as it is part of the next message
            count = 0; // Resetting the counter for the next message
        } else {
            count++; // Incrementing the counter for the current message length
        }
    }

    // Checking if the maximum message length exceeds the allowed maximum
    if (max > n) {
        cout << "Impossible" << endl; // Printing "Impossible" if the maximum message length is too large
    } else {
        int ans = 0; // Answer variable to store the number of messages
        for (int i = 0; i < idx; i++) {
            int l = msgLength[i]; // Getting the length of the current message
            while (i < idx - 1 && l + msgLength[i + 1] + 1 <= n) {
                l += msgLength[i + 1] + 1; // Grouping messages that fit within the maximum length
                i++; // Moving to the next message
            }
            ans++; // Incrementing the answer as we have a complete message
        }
        cout << ans << endl; // Printing the total number of messages required
    }
    return 0;
}

