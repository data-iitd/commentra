#include <iostream>
#include <vector>

using namespace std;

int binary_search(int key, vector<vector<int>>& ans) {
    // Initialize the boundaries for binary search
    int bad = -1, good = ans.size();
    
    // Continue searching while there is more than one element in the range
    while (good - bad > 1) {
        int mid = (bad + good) / 2;  // Calculate the middle index
        // If the last element of the mid list is less than the key, move the good boundary
        if (ans[mid].back() < key) {
            good = mid;
        } else {
            // Otherwise, move the bad boundary
            bad = mid;
        }
    }
    
    // Return the index where the key should be inserted
    return good;
}

int main() {
    // Read the number of elements
    int N;
    cin >> N;
    
    // Initialize an empty list to hold the subsequences
    vector<vector<int>> ans;
    
    // Iterate over the range of N to read each element
    for (int _ = 0; _ < N; _++) {
        int A;  // Read the current element
        cin >> A;
        int idx = binary_search(A, ans);  // Find the position to insert the element
        
        // If the index is equal to the length of ans, it means A is greater than all elements
        if (idx == ans.size()) {
            ans.push_back({A});  // Start a new subsequence with A
        } else {
            // Otherwise, append A to the existing subsequence at index idx
            ans[idx].push_back(A);
        }
    }
    
    // Print the number of subsequences formed
    cout << ans.size() << endl;
    
    return 0;
}

