#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Create a variable to read input from the console
    int N;
    long long M;

    // Read the number of elements (N) and the number of comparisons (M)
    cin >> N >> M;

    // Initialize a vector to hold the heights and a boolean vector to track valid heights
    vector<long long> H(N);
    vector<bool> ans(N, true); // Assume all heights are valid initially

    // Read the heights
    for (int i = 0; i < N; i++) {
        cin >> H[i]; // Read the height for each element
    }

    // Process M comparisons between pairs of heights
    for (int i = 0; i < M; i++) {
        int temp1, temp2;
        cin >> temp1 >> temp2; // Read the first and second index for comparison

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
    int ans2 = 0;
    for (int i = 0; i < N; i++) {
        if (ans[i]) {
            ans2++; // Increment count for each valid height
        }
    }

    // Output the count of valid heights
    cout << ans2 << endl;

    return 0;
}

// <END-OF-CODE>
