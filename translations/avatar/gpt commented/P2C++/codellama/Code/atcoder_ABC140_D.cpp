
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Generator function to parse input data
vector<string> parser() {
    vector<string> data;
    while (1) {
        // Read input and split it into a list of strings
        string input;
        getline(cin, input);
        stringstream ss(input);
        string token;
        while (ss >> token) {
            data.push_back(token);
        }
        // Yield each non-empty string as a separate value
        for (int i = 0; i < data.size(); i++) {
            if (data[i].length() > 0) {
                yield data[i];
            }
        }
        data.clear();
    }
}

// Create an instance of the input parser generator
vector<string> input_parser = parser();

// Function to get the next value from the input parser as a string
string gw() {
    global input_parser;
    return input_parser.back();
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
#include <string>
#include <algorithm>

// Read the number of elements N and the integer K from input
int N = gi();
int K = gi();
// Read the string S from input
string S = gw();

// Initialize a counter for segments
int seg_cnt = 0;

// Count the number of segments in the string S
for (int i = 0; i < N - 1; i++) {
    if (S[i] != S[i + 1]) {
        seg_cnt += 1;
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

