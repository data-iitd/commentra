#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    // Read the values of n and m
    int n, m;
    cin >> n >> m;

    // Read the list of elements
    vector<int> lst(n);
    for (int i = 0; i < n; ++i) {
        cin >> lst[i];
    }

    // Initialize a map to store the frequency of elements
    unordered_map<int, int> l;

    // Populate the map with the frequency of each element in the list
    for (int i = 0; i < n; ++i) {
        l[lst[i]]++;
    }

    // Initialize the result variable to store the final result
    long long res = 0;

    // Iterate over the list to calculate the result
    for (int i = 0; i < n; ++i) {
        if (l[lst[i]] > 1) {
            // Calculate the number of pairs that can be formed with the current element
            res += n - i - l[lst[i]];
            // Decrement the frequency of the current element in the map
            l[lst[i]]--;
        } else {
            // If the frequency is not greater than 1, calculate the number of pairs
            res += n - i - 1;
        }
    }

    // Print the final result
    cout << res << endl;

    return 0;
}

// <END-OF-CODE>
