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
    for (int i = 0; i < n; i++) {
        cin >> elems[i];
    }
    
    // Define a lambda function to check if all elements in an array are the same
    auto all_same = [](vector<int> arr) {
        return all_of(arr.begin(), arr.end(), [&](int x) { return x == arr[0]; });
    };
    
    // If all elements in elems are the same, print 0 and exit
    if (all_same(elems)) {
        cout << 0 << endl;
        return 0;
    }
    
    // If k is 1, it's impossible to satisfy the conditions, print -1 and exit
    if (k == 1) {
        cout << -1 << endl;
        return 0;
    }
    
    // If the last k-1 elements are not the same, print -1 and exit
    if (!all_same(vector<int>(elems.begin() + n - k + 1, elems.end()))) {
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

// 