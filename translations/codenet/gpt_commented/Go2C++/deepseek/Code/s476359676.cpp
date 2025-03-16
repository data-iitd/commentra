#include <iostream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Initialize variables for reading input
    int n;
    cin >> n;
    vector<int> a(n);

    // Read the integers into the vector
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // Initialize variables for the answer and the previous integer
    int ans = 0;
    int aPrev = 0;

    // Loop through each integer in the vector
    for (int i = 0; i < n; ++i) {
        int a = a[i]; // Get the current integer

        // Check conditions based on the current and previous integers
        if (a > i || a > aPrev + 1) { // If the current integer is greater than the index or previous integer + 1
            cout << -1 << endl; // Print -1 and exit
            return 0;
        } else if (a == aPrev + 1) { // If the current integer is exactly one more than the previous integer
            ans++; // Increment the answer
        } else { // For all other cases
            ans += a; // Add the current integer to the answer
        }
        aPrev = a; // Update the previous integer to the current one
    }

    // Print the final answer
    cout << ans << endl;

    return 0;
}
