#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;  // Define a constant for modulo operation

int main() {
    int N, K;  // Declare variables for number of elements and parameter K
    cin >> N >> K;  // Read the number of elements N and the parameter K from input
    string S;  // Declare a string S
    cin >> S;  // Read the string S from input

    int seg_cnt = 0;  // Initialize a counter for the number of segments
    for (int i = 0; i < N - 1; ++i) {  // Loop through the string to count segments
        if (S[i] != S[i + 1]) {  // Check if the current character is different from the next
            seg_cnt++;  // Increment the segment counter if a change is found
        }
    }

    int cur_happy = N - 1 - seg_cnt;  // Calculate the initial happiness based on the number of segments

    int ans;  // Declare a variable for the answer
    if (2 * K >= seg_cnt) {  // Check if the number of operations allows for maximum happiness
        ans = N - 1;  // If yes, set the answer to the maximum possible happiness
    } else {
        ans = cur_happy + 2 * K;  // Otherwise, adjust the happiness based on the number of operations
    }

    cout << ans << endl;  // Print the final happiness value
    return 0;  // Return 0 to indicate successful execution
}

// <END-OF-CODE>
