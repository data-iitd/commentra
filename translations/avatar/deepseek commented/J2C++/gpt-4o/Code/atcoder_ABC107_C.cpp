#include <iostream> // Include the iostream library for input and output
#include <vector>   // Include the vector library for dynamic arrays
#include <algorithm> // Include the algorithm library for min and max functions
#include <cmath>    // Include the cmath library for abs function

using namespace std;

int main() {
    int N, K; // Declare variables for N and K
    cin >> N >> K; // Read the values of N and K
    vector<int> S(N); // Create a vector S of size N

    // Read the elements of the vector S
    for (int i = 0; i < N; i++) {
        cin >> S[i];
    }

    int temp = 0; // Initialize temp to store intermediate results
    int ans = 1000000000; // Initialize ans to store the minimum difference

    // Check if K is equal to 1
    if (K == 1) {
        for (int i = 0; i < N; i++) {
            temp = S[i]; // Store the current element in temp
            ans = min(abs(temp), ans); // Update ans with the minimum absolute value
        }
        cout << ans << endl; // Print the minimum absolute value
    } else if (N - K != 0) { // Check if the length of the subarray is not zero
        for (int i = 0; i <= N - K; i++) {
            int minVal = S[i]; // Initialize min with the first element of the subarray
            int maxVal = S[i + K - 1]; // Initialize max with the last element of the subarray

            // Check if the subarray contains both positive and negative numbers
            if (minVal < 0 && maxVal > 0) {
                temp = min(2 * (-minVal) + maxVal, (-minVal) + 2 * maxVal); // Calculate the minimum difference
            } else {
                temp = max(abs(minVal), abs(maxVal)); // Calculate the maximum absolute value
            }

            ans = min(ans, temp); // Update ans with the minimum difference
        }
        cout << ans << endl; // Print the minimum difference
    } else { // If the length of the subarray is zero
        int minVal = S[0]; // Initialize min with the first element
        int maxVal = S[N - 1]; // Initialize max with the last element

        // Check if the array contains both positive and negative numbers
        if (minVal < 0 && maxVal > 0) {
            cout << min(2 * (-minVal) + maxVal, (-minVal) + 2 * maxVal) << endl; // Print the minimum difference
        } else {
            cout << max(abs(minVal), abs(maxVal)) << endl; // Print the maximum absolute value
        }
    }

    return 0; // Return 0 to indicate successful completion
}

// <END-OF-CODE>
