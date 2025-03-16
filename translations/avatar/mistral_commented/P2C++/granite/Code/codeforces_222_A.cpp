
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to define the main logic of the program
void main() {

    // Read input: number of elements 'n' and the difference 'k'
    int n, k;
    cin >> n >> k;

    // Read input: list of elements 'elems'
    vector<int> elems(n);
    for (int i = 0; i < n; i++) {
        cin >> elems[i];
    }

    // Helper function to check if all elements in a vector are the same
    bool all_same(vector<int> arr) {
        // Return true if all elements in the vector are the same, else false
        return all_of(arr.begin(), arr.end(), [arr](int x) { return x == arr[0]; });
    }

    // Check if all elements in the vector are the same
    if (all_same(elems)) {
        // If all elements are the same, print 0 and exit
        cout << 0 << endl;
        return;
    }

    // Check if difference 'k' is 1
    if (k == 1) {
        // If difference is 1, print -1 and exit
        cout << -1 << endl;
        return;
    }

    // Check if last 'k' elements in the vector are not all the same
    if (!all_same(vector<int>(elems.end() - k, elems.end()))) {
        // If last 'k' elements are not all the same, print -1 and exit
        cout << -1 << endl;
        return;
    }

    // Initialize target element
    int target = elems[elems.size() - 1];

    // Initialize vector 'to_delete' to store elements to be deleted
    vector<int> to_delete(elems.begin(), elems.end() - k);

    // While 'to_delete' is not empty and its last element is 'target'
    while (!to_delete.empty() && to_delete.back() == target) {
        // Pop the last element from 'to_delete'
        to_delete.pop_back();
    }

    // Print the size of 'to_delete'
    cout << to_delete.size() << endl;
}

