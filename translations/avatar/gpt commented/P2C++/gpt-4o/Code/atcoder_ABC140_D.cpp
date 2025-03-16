#include <iostream>
#include <string>

using namespace std;

// Function to read the next integer from input
int gi() {
    int data;
    cin >> data;
    return data;
}

// Function to read the next string from input
string gw() {
    string data;
    cin >> data;
    return data;
}

// Define a constant for the modulo operation
const int MOD = 1e9 + 7;

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
        if (S[i] != S[i + 1]) {
            seg_cnt++;
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

    return 0;
}

// <END-OF-CODE>
