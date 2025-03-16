#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Read two integers n and k from input
    int n, k;
    cin >> n >> k;
    
    // Read a list of n integers from input
    vector<int> elems(n);
    for (int i = 0; i < n; ++i) {
        cin >> elems[i];
    }
    
    // Check if all elements in elems are the same
    bool all_same = true;
    for (int i = 1; i < n; ++i) {
        if (elems[i] != elems[0]) {
            all_same = false;
            break;
        }
    }
    
    // If all elements in elems are the same, print 0 and exit
    if (all_same) {
        cout << 0 << endl;
        return 0;
    }
    
    // If k is 1, it's impossible to satisfy the conditions, print -1 and exit
    if (k == 1) {
        cout << -1 << endl;
        return 0;
    }
    
    // If the last k-1 elements are not the same, print -1 and exit
    bool last_k_same = true;
    for (int i = k - 1; i < n; ++i) {
        if (elems[i] != elems[k - 1]) {
            last_k_same = false;
            break;
        }
    }
    if (!last_k_same) {
        cout << -1 << endl;
        return 0;
    }
    
    // Set the target value to the last element of elems
    int target = elems[n - 1];
    
    // Create a list of elements to delete, which are the first k-1 elements
    vector<int> to_delete(elems.begin(), elems.begin() + k - 1);
    
    // Remove elements from to_delete that are equal to the target from the end
    while (!to_delete.empty() && to_delete.back() == target) {
        to_delete.pop_back();
    }
    
    // Print the number of elements that need to be deleted
    cout << to_delete.size() << endl;

    return 0;
}

// <END-OF-CODE>
