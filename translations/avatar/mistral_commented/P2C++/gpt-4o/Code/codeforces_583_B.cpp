#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Define the main function
int main() {
    // Read the number of test cases
    int n;
    cin >> n;

    // Read the array of integers
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Initialize variables
    int current_level = 0;
    int counter = 0;
    int counter_turns = -1;

    // Main loop
    while (counter < a.size()) {
        // Increment turns counter
        counter_turns++;

        // Iterate through the array
        for (int i = 0; i < a.size(); i++) {
            // If current index is valid and its value is less than or equal to current level
            if (a[i] != -1 && a[i] <= counter) {
                // Increment counter and mark the index as visited
                counter++;
                a[i] = -1;
            }
        }

        // Reverse the array
        reverse(a.begin(), a.end());
    }

    // Print the result
    cout << counter_turns << endl;

    return 0;
}

// <END-OF-CODE>
