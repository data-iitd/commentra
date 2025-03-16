
// Importing required packages
#include <bits/stdc++.h>

// Define a custom type 'Block'
struct Block {
    std::string Value;
    int Len;
};

// Main function starts the execution
int main() {
    // Initialize variables
    int N, K, ans = 0;

    // Read input values for N and K from the standard input
    std::cin >> N >> K;

    // Initialize a string S to store the input string
    std::string S;

    // Read the input string S from the standard input
    std::cin >> S;

    // Call the RunLength function to get the run-length encoded blocks
    std::vector<Block> blocks = RunLength(S);

    // Initialize variables sum, zero and length l
    int sum = 0, zero = 0, l = 0;

    // Loop through all the blocks in the blocks vector
    for (int r = 0; r < blocks.size(); r++) {
        // Increment the sum by the length of the current block
        sum += blocks[r].Len;

        // If the current block's value is '0', increment the zero counter
        if (blocks[r].Value == "0") {
            zero++;
        }

        // While the zero counter is greater than K, subtract the length of the previous block from the sum and decrement the zero counter
        while (K < zero) {
            sum -= blocks[l].Len;
            if (blocks[l].Value == "0") {
                zero--;
            }
            l++;
        }

        // Update the answer with the maximum of the current answer and the sum
        ans = std::max(ans, sum);
    }

    // Print the final answer
    std::cout << ans << std::endl;

    // End of the code
    return 0;
}

// RunLength function to get the run-length encoded blocks
std::vector<Block> RunLength(std::string s) {
    // If the length of the input string is zero, return an empty vector
    if (s.length() == 0) {
        return std::vector<Block>();
    }

    // Initialize the first block with the first character and length one
    Block t = {"", 1};
    t.Value = s[0];

    // Initialize an empty vector to store the blocks
    std::vector<Block> r;

    // Loop through all the characters in the input string starting from the second character
    for (int i = 1; i < s.length(); i++) {
        // If the current character is the same as the previous character, increment the length of the current block
        if (t.Value == s[i]) {
            t.Len++;
        } else {
            // Add the previous block to the result vector
            r.push_back(t);

            // Initialize a new block with the current character and length one
            t = {"", 1};
            t.Value = s[i];
        }
    }

    // Add the last block to the result vector
    r.push_back(t);

    // Return the result vector
    return r;
}

// End of the code