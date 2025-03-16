#include <bits/stdc++.h>
using namespace std;

int main() {
    // Read the number of elements (N) and the number of comparisons (M)
    int N, M;
    cin >> N >> M;
    
    // Initialize an array to hold the heights and a boolean array to track valid heights
    long long H[N];
    bool ans[N];
    
    // Read the heights and initialize the ans array to true
    for (int i = 0; i < N; i++) {
        cin >> H[i]; // Read the height for each element
        ans[i] = true; // Assume all heights are valid initially
    }
    
    // Process M comparisons between pairs of heights
    for (int i = 0; i < M; i++) {
        int temp1, temp2;
        cin >> temp1 >> temp2; // Read the first and second index for comparison
        
        // Compare the heights and update the ans array based on the comparison results
        if (H[temp1 - 1] < H[temp2 - 1]) {
            ans[temp1 - 1] = false; // temp1 is shorter, mark it as invalid
        } else if (H[temp1 - 1] > H[temp2 - 1]) {
            ans[temp2 - 1] = false; // temp2 is shorter, mark it as invalid
        } else {
            // If heights are equal, mark both as invalid
            ans[temp1 - 1] = false;
            ans[temp2 - 1] = false;
        }
    }
    
    // Count the number of valid heights
    int ans2 = 0;
    for (int i = 0; i < N; i++) {
        if (ans[i]) {
            ans2++; // Increment count for each valid height
        }
    }
    
    // Output the count of valid heights
    cout << ans2;
}

