#######
# Code
#######

# Include necessary libraries
#include <iostream>
#include <string>
#include <deque>

// Function to parse input line by line
std::string gw() {
// Continuously parse input lines
    std::string data;
    std::getline(std::cin, data);
// Process each token in the input line
    for (int i = 0; i < data.length(); i++) {
// Check if the token is empty or not
        if (data[i] != ' ') {
// Yield the token as a result of the function
            return data.substr(i);
        }
    }
}

// Function to get the next integer from the parser
int gi() {
// Get the next token as a string
    std::string data = gw();
// Convert the token to an integer
    return std::stoi(data);
}

// Global variables
const int MOD = 1e9 + 7;

// Define a deque for segment count
std::deque<int> seg_cnt;

// Get the number of segments in the string
int N = gi();

// Get the number of queries
int K = gi();

// Get the string S
std::string S = gw();

// Initialize segment count
seg_cnt.clear();

// Iterate through the string and count the number of segments
for (int i = 0; i < N - 1; i++) {
// Check if the current character is different from the next character
    if (S[i] != S[i + 1]) {
// Add 1 to the segment count
        seg_cnt.push_back(1);
    }
}

// Calculate the current happiness
int cur_happy = N - 1 - seg_cnt.size();

// Check if the number of queries is greater than or equal to the number of segments
if (2 * K >= seg_cnt.size()) {
// If yes, then the answer is the total number of segments
    int ans = N - 1;
// Otherwise, the answer is the current happiness plus twice the number of queries
} else {
    int ans = cur_happy + 2 * K;
}

// Print the answer
std::cout << ans << std::endl;

// End of code
