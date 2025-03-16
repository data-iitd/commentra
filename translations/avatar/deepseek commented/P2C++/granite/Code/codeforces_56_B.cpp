

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;  // Read the integer input N
    vector<int> A(N);  // Read the list of integers A
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    // Initialize variables to track the minimum and maximum indices where the condition is true
    int mn = N + 1, mx = -1;

    // Iterate over the range of N to find the indices where the condition is true
    for (int i = 0; i < N; i++) {
        if (i + 1!= A[i]) {
            mn = min(mn, i);  // Update mn if a smaller index is found
            mx = max(mx, i);  // Update mx if a larger index is found
        }
    }

    // Check if no indices satisfy the condition
    if (mx == -1) {
        cout << "0 0" << endl;  // Print '0 0' if no indices satisfy the condition
    } else {
        // Reverse the sublist from index mn to mx + 1 and update A
        reverse(A.begin() + mn, A.begin() + mx + 1);

        // Check if the list A is sorted
        if (is_sorted(A.begin(), A.end())) {
            cout << mn + 1 << " " << mx + 1 << endl;  // Print the indices if A is sorted
        } else {
            cout << "0 0" << endl;  // Print '0 0' if A is not sorted
        }
    }

    return 0;
}
