#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Block represents a contiguous segment of characters with a specific value and length.
struct Block {
    string Value; // The character value of the block
    int Len; // The length of the block
};

vector<Block> RunLength(const string& s) {
    vector<Block> r; // Vector to hold the resulting blocks
    if (s.empty()) {
        return r; // Return empty vector if input string is empty
    }

    // Initialize the first block with the first character of the string
    Block t = {string(1, s[0]), 1};
    for (size_t i = 1; i < s.size(); ++i) {
        // If the current character matches the block's value, increase the length
        if (t.Value == string(1, s[i])) {
            t.Len++;
        } else {
            // Otherwise, append the current block to the result and start a new block
            r.push_back(t);
            t = {string(1, s[i]), 1};
        }
    }
    // Append the last block to the result
    r.push_back(t);
    return r; // Return the vector of blocks
}

int main() {
    // Read input values for N (length of the string) and K (maximum number of '0's allowed)
    int N, K;
    cin >> N >> K;

    // Read the input string S
    string S;
    cin.ignore(); // To ignore any leftover newline character from previous input
    getline(cin, S);

    // Generate run-length encoded blocks from the input string S
    vector<Block> blocks = RunLength(S);

    // Initialize variables for the sliding window approach
    int sum = 0, zero = 0, l = 0, ans = 0;

    // Iterate through the blocks to find the maximum length of segments with at most K '0's
    for (size_t r = 0; r < blocks.size(); ++r) {
        sum += blocks[r].Len; // Add the length of the current block to the sum

        // Count the number of '0' blocks encountered
        if (blocks[r].Value == "0") {
            zero++;
        }

        // If the count of '0' blocks exceeds K, shrink the window from the left
        while (K < zero) {
            sum -= blocks[l].Len; // Subtract the length of the leftmost block from the sum
            if (blocks[l].Value == "0") {
                zero--; // Decrease the count of '0' blocks
            }
            l++; // Move the left pointer to the right
        }

        // Update the answer with the maximum sum found so far
        ans = max(ans, sum);
    }

    // Print the maximum length of segments with at most K '0's
    cout << ans << endl;

    return 0;
}
