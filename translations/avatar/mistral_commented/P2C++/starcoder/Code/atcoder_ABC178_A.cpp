#include <bits/stdc++.h>
using namespace std;

// Function to solve a single test case
void solve(int a) {
    // Print the solution for the current test case
    cout << (a == 0? 1 : 0) << endl;
}

// Driver code
int main() {
    // Read the number of test cases
    int tcs;
    cin >> tcs;

    // Iterate over all test cases
    while (tcs--) {
        // Read the next test case and store it in a variable 'a'
        int a;
        cin >> a;

        // Solve the current test case
        solve(a);
    }

    return 0;
}

