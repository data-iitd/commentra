#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    long long M;
    cin >> N >> M; // Read the number of elements N and the number of comparisons M

    vector<long long> H(N); // Initialize a vector to store the heights of N elements
    vector<bool> ans(N, true); // Initialize a boolean vector to store the result for each element

    // Read the heights of the elements into the vector H
    for (int i = 0; i < N; i++) {
        cin >> H[i];
    }

    // Read the pairs of indices (temp1 and temp2) and compare the heights at these indices
    for (long long i = 0; i < M; i++) {
        int temp1, temp2;
        cin >> temp1 >> temp2;

        if (H[temp1 - 1] < H[temp2 - 1]) {
            ans[temp1 - 1] = false; // Update the boolean vector ans based on the comparison results
        } else if (H[temp1 - 1] > H[temp2 - 1]) {
            ans[temp2 - 1] = false; // Update the boolean vector ans based on the comparison results
        } else {
            ans[temp1 - 1] = false; // Update the boolean vector ans based on the comparison results
            ans[temp2 - 1] = false; // Update the boolean vector ans based on the comparison results
        }
    }

    int ans2 = 0; // Initialize a counter to count the number of elements in the boolean vector ans that are still true
    // Count the number of elements in the boolean vector ans that are still true
    for (int i = 0; i < N; i++) {
        if (ans[i]) {
            ans2++; // Increment the counter if the element is still true
        }
    }

    cout << ans2 << endl; // Print the count
    return 0;
}

// <END-OF-CODE>
