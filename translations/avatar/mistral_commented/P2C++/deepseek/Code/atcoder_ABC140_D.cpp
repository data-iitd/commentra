#include <iostream>
#include <vector>
#include <deque>
#include <string>

using namespace std;

// Function to parse input line by line
void parser(vector<string>& tokens) {
    string line;
    while (getline(cin, line)) {
        // Split the line into tokens
        size_t start = 0, end = 0;
        while ((end = line.find(' ', start)) != string::npos) {
            tokens.push_back(line.substr(start, end - start));
            start = end + 1;
        }
        tokens.push_back(line.substr(start));
    }
}

// Function to get the next token from the parser
string gw() {
    string token;
    cin >> token;
    return token;
}

// Function to get the next integer from the parser
int gi() {
    string token = gw();
    return stoi(token);
}

// Global variables
const int MOD = 1e9 + 7;

// Import additional libraries for scientific computing
#include <vector>
#include <algorithm>

// Define a deque for segment count
deque<int> seg_cnt;

// Get the number of segments in the string
int N;

// Get the number of queries
int K;

// Get the string S
string S;

// Initialize segment count
void init() {
    seg_cnt.clear();
}

// Iterate through the string and count the number of segments
void count_segments() {
    for (int i = 0; i < N - 1; ++i) {
        if (S[i] != S[i + 1]) {
            seg_cnt.push_back(1);
        }
    }
}

// Calculate the current happiness
int calculate_happiness() {
    int cur_happy = N - 1 - seg_cnt.size();
    if (2 * K >= seg_cnt.size()) {
        return N - 1;
    } else {
        return cur_happy + 2 * K;
    }
}

int main() {
    // Parse input
    vector<string> tokens;
    parser(tokens);

    // Initialize variables
    N = stoi(tokens[0]);
    K = stoi(tokens[1]);
    S = tokens[2];

    // Initialize segment count
    init();

    // Count segments
    count_segments();

    // Calculate and print the answer
    int ans = calculate_happiness();
    cout << ans << endl;

    return 0;
}

