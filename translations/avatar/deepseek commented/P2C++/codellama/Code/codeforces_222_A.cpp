
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
    for (int i = 0; i < n; i++) {
        cin >> elems[i];
    }
    
    // Define a lambda function to check if all elements in a list are the same
    auto all_same = [](vector<int> arr) {
        return all_of(arr.begin(), arr.end(), [&](int x) { return x == arr[0]; });
    };
    
    // Check if all elements in the list are the same
    if (all_same(elems)) {
        // If all elements are the same, print 0 and return
        cout << 0 << endl;
        return 0;
    }
    
    // If k is 1, print -1 and return
    if (k == 1) {
        cout << -1 << endl;
        return 0;
    }
    
    // Check if elements from index k-1 to the end are all the same
    if (!all_same(vector<int>(elems.begin() + k - 1, elems.end()))) {
        // If not, print -1 and return
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

