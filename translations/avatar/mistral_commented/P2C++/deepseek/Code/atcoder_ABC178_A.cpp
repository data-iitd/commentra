#include <iostream>
using namespace std;

// Function to solve a single test case
void solve(int tc) {
    int a;
    cin >> a;
    cout << (a == 0 ? 1 : 0) << endl;
}

int main() {
    // Initialize the number of test cases and the test case counter
    int tcs = 1;
    int tc = 1;

    // Run the solution function for each test case
    while (tc <= tcs) {
        // Solve the current test case
        solve(tc);

        // Increment the test case counter
        tc++;
    }

    return 0;
}
