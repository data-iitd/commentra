#include <iostream>
#include <deque>
#include <string>

using namespace std;

// Function to get the next integer from input
int gi() {
    int data;
    cin >> data;
    return data;
}

int main() {
    // Define a deque for segment count
    deque<int> seg_cnt;

    // Get the number of segments in the string
    int N = gi();

    // Get the number of queries
    int K = gi();

    // Get the string S
    string S;
    cin >> S;

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
    int ans;
    if (2 * K >= seg_cnt.size()) {
        // If yes, then the answer is the total number of segments
        ans = N - 1;
    } else {
        // Otherwise, the answer is the current happiness plus twice the number of queries
        ans = cur_happy + 2 * K;
    }

    // Print the answer
    cout << ans << endl;

    return 0;
}

// <END-OF-CODE>
