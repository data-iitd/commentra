
#include <bits/stdc++.h>
using namespace std;

int main() {
    // Reading number of elements
    int N;
    cin >> N;
    // Reading list of elements
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    // Removing consecutive duplicates from list A
    A.erase(unique(A.begin(), A.end()), A.end());
    // Updating N to reflect the new length of A
    N = A.size();

    // Initializing variables for main logic
    int i = 1;
    int ans = 0;

    // Main logic to find peaks
    while (i < N - 1) {
        if (A[i - 1] < A[i] > A[i + 1] || A[i - 1] > A[i] < A[i + 1]) {
            ans += 1;
            i += 1;  // Skip next element as it's already checked
        }
        i += 1;
    }

    // Output the total number of peaks found
    cout << ans + 1 << endl;

    return 0;
}

