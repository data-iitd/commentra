#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    // Initialize variables to read input
    int N, K;
    cin >> N >> K; // Read the number of elements in the array and the size of the sliding window

    // Allocate a vector to store the input elements
    vector<int> S(N);

    // Read the remaining elements of the array from the standard input
    for (int i = 0; i < N; i++) {
        cin >> S[i]; // Read the next integer and store it in the vector
    }

    // Initialize variables for calculating the answer
    int temp = 0;
    int ans = 1000000000;

    // Check the special case when the size of the sliding window is 1
    if (K == 1) {
        // Iterate through the array to find the minimum absolute value
        for (int i = 0; i < N; i++) {
            temp = S[i]; // Read the current element
            ans = min(abs(temp), ans); // Update the answer if necessary
        }

        // Print the answer
        cout << ans << endl;
    } else if (N - K != 0) { // Check the case when the size of the sliding window is not equal to the size of the array
        // Initialize variables for calculating the minimum and maximum elements in the sliding window
        int min, max;

        // Iterate through all possible positions of the sliding window
        for (int i = 0; i <= N - K; i++) {
            // Find the minimum and maximum elements in the current sliding window
            min = S[i];
            max = S[i + K - 1];

            // Calculate the sum of the absolute values of the minimum and maximum elements
            // and update the answer if necessary
            if (min < 0 && max > 0) {
                temp = 2 * (abs(min)) + max;
            } else {
                temp = max(abs(min), abs(max));
            }
            ans = min(ans, temp);
        }

        // Print the answer
        cout << ans << endl;
    } else { // Check the case when the size of the sliding window is equal to the size of the array
        // Find the minimum and maximum elements in the array
        min = S[0];
        max = S[N - 1];

        // Calculate the sum of the absolute values of the minimum and maximum elements
        // and print the answer directly
        if (min < 0 && max > 0) {
            cout << min(2 * (abs(min)) + max, (abs(min)) + 2 * max) << endl;
        } else {
            cout << max(abs(min), abs(max)) << endl;
        }
    }

    return 0; // End of the program
}

// <END-OF-CODE>
