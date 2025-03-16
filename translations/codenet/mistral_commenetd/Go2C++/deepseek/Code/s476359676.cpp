#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main() {
    // Initialize variables for reading input
    int n;
    cin >> n;

    // Initialize variables for processing the input
    int ans = 0;
    int aPrev = 0;

    // Process each test case
    for (int i = 0; i < n; i++) {
        // Read the next integer as 'a'
        int a;
        cin >> a;

        // Check if 'a' is valid based on the conditions in the problem statement
        if (a > i || a > aPrev + 1) { // 'a' is not valid, print -1 and exit
            cout << -1 << endl;
            return 0;
        } else if (a == aPrev + 1) { // Increment the answer if 'a' is consecutive with the previous number
            ans++;
        } else { // Add 'a' to the answer if it's not consecutive but greater than the previous number
            ans += a;
        }

        // Update the previous number
        aPrev = a;
    }

    // Print the final answer
    cout << ans << endl;

    // End of code
    return 0;
}
