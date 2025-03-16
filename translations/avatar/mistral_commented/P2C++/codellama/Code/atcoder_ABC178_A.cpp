#include <iostream>
using namespace std;

// Function to solve a single test case
void solve(int tc) {
    // Read the next test case and store it in a variable 'a'
    int a;
    cin >> a;

    // Print the solution for the current test case
    cout << (a == 0 ? 1 : 0) << endl;
}

// Initialize the number of test cases and the test case counter
int tcs, tc;

// Run the solution function for each test case
int main() {
    cin >> tcs;
    tc = 1;
    while (tc <= tcs) {
        // Solve the current test case
        solve(tc);

        // Increment the test case counter
        tc++;
    }

    return 0;
}

