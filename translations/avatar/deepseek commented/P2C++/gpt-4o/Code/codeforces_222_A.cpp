#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Read the number of elements (n) and the parameter (k)
    int n, k;
    cin >> n >> k;
    
    // Read the list of elements
    vector<int> elems(n);
    for (int i = 0; i < n; ++i) {
        cin >> elems[i];
    }
    
    // Check if all elements in the list are the same
    bool all_same = true;
    for (int i = 1; i < n; ++i) {
        if (elems[i] != elems[0]) {
            all_same = false;
            break;
        }
    }
    
    // If all elements are the same, print 0 and return
    if (all_same) {
        cout << 0 << endl;
        return 0;
    }
    
    // If k is 1, print -1 and return
    if (k == 1) {
        cout << -1 << endl;
        return 0;
    }
    
    // Check if elements from index k-1 to the end are all the same
    all_same = true;
    for (int i = k; i < n; ++i) {
        if (elems[i] != elems[k-1]) {
            all_same = false;
            break;
        }
    }
    
    // If not, print -1 and return
    if (!all_same) {
        cout << -1 << endl;
        return 0;
    }
    
    // Set the target to the last element of the list
    int target = elems.back();
    
    // Initialize to_delete as elements from the start to k-1
    vector<int> to_delete(elems.begin(), elems.begin() + k - 1);
    
    // Remove elements from to_delete that are equal to target until a different element is found
    while (!to_delete.empty() && to_delete.back() == target) {
        to_delete.pop_back();
    }
    
    // Print the length of to_delete
    cout << to_delete.size() << endl;

    return 0;
}

// <END-OF-CODE>
