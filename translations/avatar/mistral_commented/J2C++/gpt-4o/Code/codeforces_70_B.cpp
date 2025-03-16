#include <iostream> // Include iostream for input and output
#include <sstream>  // Include sstream for string stream
#include <vector>   // Include vector for dynamic array
#include <string>   // Include string for string manipulation

using namespace std;

int main() {
    int n; // Variable to store the number of messages
    cin >> n; // Read the number of messages
    cin.ignore(); // Ignore the newline character after reading n

    string input; // String to store the input messages
    getline(cin, input); // Read the entire line of messages

    int max = -1; // Initialize max to -1
    vector<int> msgLength; // Vector to store lengths of messages
    int count = 0; // Initialize count to 0

    // Loop through each character in the input string
    for (char c : input) {
        if (c == '.' || c == '?' || c == '!') { // If character is a question mark, exclamation mark or period
            msgLength.push_back(++count); // Increment count and store it in msgLength vector
            if (count > max) max = count; // Update max if count is greater than current max
            count = 0; // Reset count as we have started a new message
        } else {
            count++; // Increment count if character is not a question mark, exclamation mark or period
        }
    }

    // Check if the total length of messages is greater than n
    if (max > n) {
        cout << "Impossible" << endl; // Print "Impossible" if total length is greater than n
        return 0; // Exit the program
    }

    int ans = 0; // Initialize answer to 0
    int idx = msgLength.size(); // Get the number of messages

    // Loop through each message and find the maximum number of messages that can be sent
    for (int i = 0; i < idx; i++) {
        int l = msgLength[i]; // Initialize length of current message

        while (i < idx - 1 && l + msgLength[i + 1] + 1 <= n) { // While we can add next message to current message
            l += msgLength[i + 1] + 1; // Add length of next message and 1 for separator
            i++; // Increment i to move to next message
        }
        ans++; // Increment answer as we have added one more message
    }

    cout << ans << endl; // Print the answer
    return 0; // Exit the program
}

// <END-OF-CODE>
