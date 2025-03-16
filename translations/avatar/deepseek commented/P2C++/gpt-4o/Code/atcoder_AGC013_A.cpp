#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;  // Reading number of elements
    vector<int> A(N);
    
    for (int i = 0; i < N; ++i) {
        cin >> A[i];  // Reading list of elements
    }

    // Removing consecutive duplicates from list A
    auto last = unique(A.begin(), A.end());
    A.erase(last, A.end());
    N = A.size();  // Updating N to reflect the new length of A

    // Initializing variables for main logic
    int i = 1;
    int ans = 0;

    // Main logic to find peaks
    while (i < N - 1) {
        if ((A[i - 1] < A[i] && A[i] > A[i + 1]) || (A[i - 1] > A[i] && A[i] < A[i + 1])) {
            ans += 1;
            i += 1;  // Skip next element as it's already checked
        }
        i += 1;
    }

    // Output the total number of peaks found
    cout << ans + 1 << endl;

    return 0;
}

// <END-OF-CODE>
