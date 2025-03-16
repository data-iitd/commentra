
#include <iostream> // Importingiostream for input/output operations
#include <string> // Importing string for string manipulation

using namespace std;

int main() {
    int n; // Maximum length for each message
    string input; // Input text

    cin >> n; // Reading the maximum length for each message
    getline(cin, input); // Reading the input text

    int max = -1; // Initializing the maximum message length to -1
    int msgLength[input.length() / 2]; // Initializing an array to store the lengths of each message
    int count = 0; // Initializing a counter for the current message length
    int idx = 0; // Index for the msgLength array

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
        int ans = 0; // Initializing the answer variable to store the number of messages
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

    return 0; // Returning 0 to indicate successful execution
}
