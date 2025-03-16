#include <iostream> // Including iostream for input and output operations
#include <sstream> // Including sstream for string stream operations
#include <vector> // Including vector for dynamic array operations
#include <string> // Including string for string operations

using namespace std;

int main() {
    int n; // Variable to store the maximum length for each message
    cin >> n; // Reading the maximum length for each message
    cin.ignore(); // Ignoring the newline character after the integer input
    string input; // String to store the input text
    getline(cin, input); // Reading the input text

    int max = -1; // Initializing the maximum message length to -1
    vector<int> msgLength; // Vector to store the lengths of each message
    int count = 0; // Initializing a counter for the current message length

    // Iterating through the input string to determine message lengths
    for (char c : input) {
        if (c == '.' || c == '?' || c == '!') {
            msgLength.push_back(++count); // Storing the length of the current message
            if (count > max) max = count; // Updating the maximum message length if necessary
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
        for (size_t i = 0; i < msgLength.size(); i++) {
            int l = msgLength[i]; // Getting the length of the current message
            while (i < msgLength.size() - 1 && l + msgLength[i + 1] + 1 <= n) {
                l += msgLength[i + 1] + 1; // Grouping messages that fit within the maximum length
                i++; // Moving to the next message
            }
            ans++; // Incrementing the answer as we have a complete message
        }
        cout << ans << endl; // Printing the total number of messages required
    }

    return 0; // Returning 0 to indicate successful execution
}

// <END-OF-CODE>
