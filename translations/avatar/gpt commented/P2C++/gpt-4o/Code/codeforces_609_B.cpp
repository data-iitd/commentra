#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    // Read the values of n and m from input
    int n, m;
    cin >> n >> m;

    // Read a list of integers from input
    vector<int> lst(n);
    for (int i = 0; i < n; ++i) {
        cin >> lst[i];
    }

    // Initialize a map to count occurrences of each integer in the list
    unordered_map<int, int> l;

    // Count the occurrences of each integer in the list
    for (int i = 0; i < n; ++i) {
        l[lst[i]]++;
    }

    // Initialize the result variable to store the final count
    long long res = 0;

    // Calculate the result based on the occurrences of integers
    for (int i = 0; i < n; ++i) {
        if (l[lst[i]] > 1) {
            // If the current integer appears more than once
            res += n - i - l[lst[i]];  // Add the number of valid pairs
            l[lst[i]]--;  // Decrease the count of this integer
        } else {
            // If the current integer appears only once
            res += n - i - 1;  // Add the number of valid pairs for unique integers
        }
    }

    // Print the final result
    cout << res << endl;

    return 0;
}

// <END-OF-CODE>
