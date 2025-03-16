#include <iostream>
#include <string>
#include <deque>

using namespace std;

// Function to parse input data
string parser() {
    string data;
    getline(cin, data);
    deque<string> tokens;
    size_t pos = 0, prev = 0;
    while ((pos = data.find(' ', prev)) != string::npos) {
        tokens.push_back(data.substr(prev, pos - prev));
        prev = pos + 1;
    }
    tokens.push_back(data.substr(prev));
    for (const auto& token : tokens) {
        if (!token.empty()) {
            return token;
        }
    }
    return "";
}

// Function to get the next value from the input parser as a string
string gw() {
    return parser();
}

// Function to get the next value from the input parser and convert it to an integer
int gi() {
    string data = gw();
    return stoi(data);
}

// Define a constant for the modulo operation
const int MOD = 1e9 + 7;

// Import necessary libraries
#include <vector>
#include <algorithm>

// Read the number of elements N and the integer K from input
int N = gi();
int K = gi();
// Read the string S from input
string S = gw();

// Initialize a counter for segments
int seg_cnt = 0;

// Count the number of segments in the string S
for (int i = 0; i < N - 1; ++i) {
    if (S[i] != S[i + 1]) {
        ++seg_cnt;
    }
}

// Calculate the current happiness based on the number of segments
int cur_happy = N - 1 - seg_cnt;

// Determine the final answer based on the relationship between K and seg_cnt
int ans;
if (2 * K >= seg_cnt) {
    ans = N - 1;  // If K is sufficient to cover all segments
} else {
    ans = cur_happy + 2 * K;  // Otherwise, calculate based on current happiness and K
}

// Print the final answer
cout << ans << endl;

