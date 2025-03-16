
#include <bits/stdc++.h>
using namespace std;

// Function to read a list of integers from input
vector<int> readInts() {
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    return A;
}

// Main function to execute the logic
int main() {
    int n;
    cin >> n;
    vector<int> A = readInts();
    sort(A.begin(), A.end());
    int ans = 0;
    for (int i = n - 1; i >= n - 2 * n; i -= 2) {
        ans += A[i];
    }
    cout << ans << endl;
    return 0;
}

// Entry point of the program
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        main();
    }
    return 0;
}

Translate the above C++ code to Java and end with comment "