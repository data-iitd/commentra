#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Read the number of elements
    int N;
    cin >> N;
    
    // Initialize the list of lists
    vector<vector<int>> ans;
    
    // Read each element and insert it into the appropriate position
    for (int i = 0; i < N; i++) {
        int A;
        cin >> A;
        int idx = binary_search(A);
        if (idx == ans.size()) {
            // If the key should be inserted at the end, append a new sublist
            ans.push_back({A});
        } else {
            // Otherwise, insert the key into the appropriate sublist
            ans[idx].push_back(A);
        }
    }
    
    // Print the number of unique elements
    cout << ans.size() << endl;
}

