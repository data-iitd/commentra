
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Create a Scanner object to read input from the console
    // Read the number of elements (N) and the number of comparisons (M)
    int N, M;
    cin >> N >> M;

    // Initialize a vector to hold the heights and a boolean vector to track valid heights
    vector<int> H(N);
    vector<bool> ans(N, true);

    // Read the heights and initialize the ans vector to true
    for (int i = 0; i < N; i++) {
        cin >> H[i]; // Read the height for each element
        ans[i] = true; // Assume all heights are valid initially
    }

    // Process M comparisons between pairs of heights
    for (int i = 0; i < M; i++) {
        int temp1, temp2;
        cin >> temp1 >> temp2; // Read the first index for comparison and the second index for comparison

        // Compare the heights and update the ans vector based on the comparison results
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
    int ans2 = count(ans.begin(), ans.end(), true);

    // Output the count of valid heights
    cout << ans2 << endl; // Output the count of valid heights

    return 0;
}
