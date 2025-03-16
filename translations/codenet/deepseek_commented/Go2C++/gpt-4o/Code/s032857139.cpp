#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>

using namespace std;

// Utility functions for reading input.
int ReadInt() {
    int x;
    cin >> x;
    return x;
}

vector<int> ReadIntSlice(int n) {
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        b[i] = ReadInt();
    }
    return b;
}

// Main function to read input, sort the array, and calculate the answer.
int main() {
    int n = ReadInt();
    int x = ReadInt();
    vector<int> A = ReadIntSlice(n);

    sort(A.begin(), A.end());

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (x >= A[i]) {
            ans++;
            x -= A[i];
        } else {
            break;
        }
    }
    if (ans == n && x > 0) {
        ans--;
    }
    cout << ans << endl;

    return 0;
}

// <END-OF-CODE>
