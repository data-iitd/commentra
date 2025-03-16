// Importing required headers
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

// Define a custom structure 'Block'
struct Block {
    std::string Value;
    int Len;
};

// Function to perform run-length encoding
std::vector<Block> RunLength(const std::string& s) {
    // If the length of the input string is zero, return an empty vector
    if (s.empty()) {
        return {};
    }

    // Initialize the first block with the first character and length one
    Block t = {std::string(1, s[0]), 1};
    std::vector<Block> r;

    // Loop through all the characters in the input string starting from the second character
    for (size_t i = 1; i < s.size(); ++i) {
        // If the current character is the same as the previous character, increment the length of the current block
        if (t.Value == std::string(1, s[i])) {
            t.Len++;
        } else {
            // Add the previous block to the result vector
            r.push_back(t);
            // Initialize a new block with the current character and length one
            t = {std::string(1, s[i]), 1};
        }
    }

    // Add the last block to the result vector
    r.push_back(t);
    return r;
}

// Function to find the maximum of two integers
int Max(int a, int b) {
    return (b > a) ? b : a;
}

// Main function starts the execution
int main() {
    // Initialize variables
    int N, K, ans = 0;

    // Read input values for N and K from the standard input
    std::cin >> N >> K;

    // Read the input string S from the standard input
    std::string S;
    std::cin >> S;

    // Call the RunLength function to get the run-length encoded blocks
    std::vector<Block> blocks = RunLength(S);

    // Initialize variables sum, zero and length l
    int sum = 0, zero = 0, l = 0;

    // Loop through all the blocks in the blocks vector
    for (size_t r = 0; r < blocks.size(); r++) {
        // Increment the sum by the length of the current block
        sum += blocks[r].Len;

        // If the current block's value is '0', increment the zero counter
        if (blocks[r].Value == "0") {
            zero++;
        }

        // While the zero counter is greater than K, subtract the length of the previous block from the sum and decrement the zero counter
        while (zero > K) {
            sum -= blocks[l].Len;
            if (blocks[l].Value == "0") {
                zero--;
            }
            l++;
        }

        // Update the answer with the maximum of the current answer and the sum
        ans = Max(ans, sum);
    }

    // Print the final answer
    std::cout << ans << std::endl;

    return 0;
}

// <END-OF-CODE>
