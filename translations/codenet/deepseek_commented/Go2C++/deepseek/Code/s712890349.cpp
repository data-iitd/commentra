#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Block represents a run-length encoded block of characters
struct Block {
    string Value;
    int Len;
};

vector<Block> RunLength(const string& s) {
    vector<Block> r; // Initialize a vector to store the encoded blocks
    if (s.empty()) {
        return r; // Return an empty vector if the input string is empty
    }
    Block t = {string(1, s[0]), 1}; // Initialize the first block
    for (size_t i = 1; i < s.size(); ++i) {
        if (t.Value == string(1, s[i])) {
            t.Len++; // Increment the length of the current block if the character is the same
        } else {
            r.push_back(t); // Append the current block to the result vector
            t = {string(1, s[i]), 1}; // Initialize a new block for the new character
        }
    }
    r.push_back(t); // Append the last block to the result vector
    return r;
}

int main() {
    int N, K, ans = 0; // Declare variables for the number of characters, maximum allowed changes, and the answer
    cin >> N >> K; // Read the number of characters and the maximum allowed changes from the standard input
    string S; // Declare a string to store the input string
    cin >> S; // Read the input string from the standard input

    // Apply Run Length Encoding to the input string S
    vector<Block> blocks = RunLength(S);

    // Initialize variables for the sliding window approach
    int sum = 0, zero = 0, l = 0;
    for (size_t r = 0; r < blocks.size(); ++r) {
        sum += blocks[r].Len; // Add the length of the current block to the sum
        if (blocks[r].Value == "0") {
            zero++; // Increment the count of '0' blocks
        }
        // Adjust the window size if the number of '0' blocks exceeds K
        while (K < zero) {
            sum -= blocks[l].Len; // Subtract the length of the block at the left of the window
            if (blocks[l].Value == "0") {
                zero--; // Decrement the count of '0' blocks
            }
            l++; // Move the left pointer to the right
        }
        ans = max(ans, sum); // Update the answer if the current window sum is greater
    }
    cout << ans << endl; // Print the final answer
    return 0;
}
