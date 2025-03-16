#include <iostream>
#include <vector>

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

    // Helper function to check if all elements in a list are the same
    bool all_same(vector<int> arr) {
        // Return True if all elements in the list are the same, else False
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i]!= arr[0]) {
                return false;
            }
        }
        return true;
    }

    // Check if all elements in the list are the same
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

    // Check if last 'k' elements in the list are not all the same
    if (!all_same(elems.end() - k, elems.end())) {
        // If last 'k' elements are not all the same, print -1 and exit
        cout << -1 << endl;
        return;
    }

    // Initialize target element
    int target = elems[n - 1];

    // Initialize list 'to_delete' to store elements to be deleted
    vector<int> to_delete;
    for (int i = 0; i < k - 1; i++) {
        to_delete.push_back(elems[i]);
    }

    // While 'to_delete' is not empty and its last element is 'target'
    while (to_delete.size() && to_delete[to_delete.size() - 1] == target) {
        // Pop the last element from 'to_delete'
        to_delete.pop_back();
    }

    // Print the length of 'to_delete'
    cout << to_delete.size() << endl;
}

