#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Constants for the program
const int MOD = 1000000000 + 7;

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> A(n);

    // Read input values into the array A
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    // Sort the array A
    sort(A.begin(), A.end());

    // Initialize answer variable
    int ans = 0;

    // Count how many elements can be taken from A without exceeding x
    for (int i = 0; i < n; i++) {
        if (x >= A[i]) {
            ans++;
            x -= A[i];
        } else {
            break;
        }
    }

    // Adjust answer if all elements are taken and there is still remaining x
    if (ans == n && x > 0) {
        ans--;
    }

    // Print the final answer
    cout << ans << endl;

    return 0;
}

// <END-OF-CODE>
