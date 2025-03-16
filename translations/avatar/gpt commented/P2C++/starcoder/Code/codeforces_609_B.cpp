#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    // Read the values of n and m from input
    int n, m;
    cin >> n >> m;

    // Read a list of integers from input
    vector<int> lst(n);
    for (int i = 0; i < n; i++) {
        cin >> lst[i];
    }

    // Initialize a dictionary to count occurrences of each integer in the list
    map<int, int> l;

    // Count the occurrences of each integer in the list
    for (int i = 0; i < n; i++) {
        if (l.find(lst[i]) == l.end()) {
            // If the integer is not in the dictionary, add it with a count of 1
            l[lst[i]] = 1;
        } else {
            // If the integer is already in the dictionary, increment its count
            l[lst[i]] += 1;
        }
    }

    // Initialize the result variable to store the final count
    int res = 0;

    // Calculate the result based on the occurrences of integers
    for (int i = 0; i < n; i++) {
        if (l[lst[i]] > 1) {
            // If the current integer appears more than once
            res += n - i - l[lst[i]];  // Add the number of valid pairs
            l[lst[i]] -= 1;  // Decrease the count of this integer
        } else {
            // If the current integer appears only once
            res += n - i - 1;  // Add the number of valid pairs for unique integers
        }
    }

    // Print the final result
    cout << res << endl;

    return 0;
}

