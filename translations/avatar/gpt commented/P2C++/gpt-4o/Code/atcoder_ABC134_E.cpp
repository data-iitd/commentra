#include <iostream>
#include <vector>

using namespace std;

int binary_search(int key, const vector<vector<int>>& ans) {
    int bad = -1, good = ans.size();
    
    while (good - bad > 1) {
        int mid = (bad + good) / 2;  // Calculate the middle index
        if (ans[mid].back() < key) {
            good = mid;  // Move the good boundary
        } else {
            bad = mid;   // Move the bad boundary
        }
    }
    
    return good;  // Return the index where the key should be inserted
}

int main() {
    int N;
    cin >> N;  // Read the number of elements

    vector<vector<int>> ans;  // Initialize an empty list to hold the subsequences

    for (int i = 0; i < N; ++i) {
        int A;
        cin >> A;  // Read the current element
        int idx = binary_search(A, ans);  // Find the position to insert the element
        
        if (idx == ans.size()) {
            ans.push_back(vector<int>{A});  // Start a new subsequence with A
        } else {
            ans[idx].push_back(A);  // Append A to the existing subsequence at index idx
        }
    }

    cout << ans.size() << endl;  // Print the number of subsequences formed

    return 0;
}

// <END-OF-CODE>
