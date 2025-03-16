#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> S(N);
    
    // Read the elements of the array S
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
            int min = S[i]; // Initialize min with the first element of the subarray
            int max = S[i + K - 1]; // Initialize max with the last element of the subarray
            
            // Check if the subarray contains both positive and negative numbers
            if (min < 0 && max > 0) {
                temp = min(2 * (-min) + max, (-min) + 2 * max); // Calculate the minimum difference
            } else {
                temp = max(abs(min), abs(max)); // Calculate the maximum absolute value
            }
            
            ans = min(ans, temp); // Update ans with the minimum difference
        }
        cout << ans << endl; // Print the minimum difference
    } else { // If the length of the subarray is zero
        int min = S[0]; // Initialize min with the first element
        int max = S[N - 1]; // Initialize max with the last element
        
        // Check if the array contains both positive and negative numbers
        if (min < 0 && max > 0) {
            cout << min(2 * (-min) + max, (-min) + 2 * max) << endl; // Print the minimum difference
        } else {
            cout << max(abs(min), abs(max)) << endl; // Print the maximum absolute value
        }
    }
    
    return 0;
}
