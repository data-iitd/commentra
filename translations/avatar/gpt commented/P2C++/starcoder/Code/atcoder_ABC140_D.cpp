#include <bits/stdc++.h>

using namespace std;

// Function to get the next value from the input parser as a string
string gw() {
    string s;
    getline(cin, s);
    return s;
}

// Function to get the next value from the input parser and convert it to an integer
int gi() {
    return stoi(gw());
}

// Define a constant for the modulo operation
const int MOD = int(1e9 + 7);

// Main function
int main() {
    // Read the number of elements N and the integer K from input
    int N = gi();
    int K = gi();
    // Read the string S from input
    string S = gw();

    // Initialize a counter for segments
    int seg_cnt = 0;

    // Count the number of segments in the string S
    for (int i = 0; i < N - 1; i++) {
        if (S[i]!= S[i + 1]) {
            seg_cnt++;
        }
    }

    // Calculate the current happiness based on the number of segments
    int cur_happy = N - 1 - seg_cnt;

    // Determine the final answer based on the relationship between K and seg_cnt
    if (2 * K >= seg_cnt) {
        int ans = N - 1;  // If K is sufficient to cover all segments
    } else {
        int ans = cur_happy + 2 * K;  // Otherwise, calculate based on current happiness and K
    }

    // Print the final answer
    cout << ans << endl;

    return 0;
}

