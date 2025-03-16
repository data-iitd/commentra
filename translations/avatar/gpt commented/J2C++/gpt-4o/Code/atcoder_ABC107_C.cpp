#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    // Create a variable to read input from the console
    int N, K;
    
    // Read the number of elements (N) and the size of the subset (K)
    cin >> N >> K;
    
    // Initialize a vector to store the input integers
    vector<int> S(N);
    
    // Read N integers into the vector S
    for (int i = 0; i < N; i++) {
        cin >> S[i];
    }
    
    // Initialize temporary variable and answer variable with a large number
    int temp = 0;
    int ans = 1000000000;

    // Case when K is 1: Find the minimum absolute value in the array
    if (K == 1) {
        for (int i = 0; i < N; i++) {
            temp = S[i];
            ans = min(abs(temp), ans); // Update ans with the minimum absolute value
        }
        // Output the result
        cout << ans << endl;
    } 
    // Case when K is not equal to N: Calculate the minimum value based on subsets of size K
    else if (N - K != 0) {
        for (int i = 0; i <= N - K; i++) {
            int minVal = S[i]; // Minimum value in the current subset
            int maxVal = S[i + K - 1]; // Maximum value in the current subset
            
            // Calculate temp based on the values of min and max
            if (minVal < 0 && maxVal > 0) {
                // If the subset contains both negative and positive values
                temp = min(2 * (-minVal) + maxVal, (-minVal) + 2 * maxVal);
            } else {
                // If the subset contains only negative or only positive values
                temp = max(abs(minVal), abs(maxVal));
            }
            
            // Update the answer with the minimum value found
            ans = min(ans, temp);
        }
        // Output the result
        cout << ans << endl;
    } 
    // Case when K is equal to N: Handle the entire array as a single subset
    else {
        int minVal = S[0]; // Minimum value in the array
        int maxVal = S[N - 1]; // Maximum value in the array
        
        // Check if the array contains both negative and positive values
        if (minVal < 0 && maxVal > 0) {
            // Calculate and print the minimum value based on the formula
            cout << min(2 * (-minVal) + maxVal, (-minVal) + 2 * maxVal) << endl;
        } else {
            // Print the maximum absolute value
            cout << max(abs(minVal), abs(maxVal)) << endl;
        }
    }
    
    return 0;
}

// <END-OF-CODE>
