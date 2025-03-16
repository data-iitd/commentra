#######
# Code
#######

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Read the number of elements in the list 'A'
    int N;
    cin >> N;

    // Initialize an empty list 'A' with the given size 'N'
    // and read the elements from the standard input
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    // Initialize minimum and maximum indices 'mn' and 'mx'
    int mn = N + 1, mx = -1;

    // Iterate through the list 'A' from index 0 to 'N-1'
    for (int i = 0; i < N; i++) {
        // Check if the current index 'i' is not equal to the next element
        if (i + 1 != A[i]) {
            // Update the minimum and maximum indices 'mn' and 'mx'
            mn = min(mn, i);
            mx = max(mx, i);
        }
    }

    // Check if the maximum index 'mx' is still equal to -1
    if (mx == -1) {
        // If yes, print '0 0' as the output
        cout << "0 0" << endl;
    } else {
        // Slice the list 'A' based on the indices 'mn' and 'mx+1'
        vector<int> A1(A.begin(), A.begin() + mn);
        vector<int> A2(A.begin() + mn, A.begin() + (mx + 1));
        vector<int> A3(A.begin() + (mx + 1), A.end());
        A = A1;
        reverse(A2.begin(), A2.end());
        A.insert(A.end(), A2.begin(), A2.end());
        A.insert(A.end(), A3.begin(), A3.end());

        // Check if the sliced list 'A' is sorted in ascending order
        if (is_sorted(A.begin(), A.end())) {
            // If yes, print the minimum and maximum indices 'mn+1' and 'mx+1' as the output
            cout << mn + 1 << " " << mx + 1 << endl;
        } else {
            // If no, print '0 0' as the output
            cout << "0 0" << endl;
        }
    }

    return 0;
}

