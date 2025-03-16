#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Read the number of elements
    int n;
    cin >> n;

    // Read the list 't' and prepend a 0 for 1-based indexing
    vector<int> t(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> t[i];
    }

    // Read the list 'a' and prepend a 0 for 1-based indexing
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    // Initialize the answer vector and a count vector to track occurrences
    vector<int> ans;
    vector<int> cnt(n + 1, 0);

    // Count the occurrences of each element in list 'a'
    for (int i = 1; i <= n; ++i) {
        cnt[a[i]]++;
    }

    // Iterate through each index from 1 to n
    for (int i = 1; i <= n; ++i) {
        // Check if the current element in 't' is 1
        if (t[i] == 1) {
            // Initialize a current path vector starting with the current index
            vector<int> crt;
            crt.push_back(i);
            // Set x to the corresponding value in 'a'
            int x = a[i];

            // Continue to follow the chain while the count of x is 1
            while (cnt[x] == 1) {
                crt.push_back(x);  // Add x to the current path
                x = a[x];  // Move to the next index in the chain
            }

            // Update the answer if the current path is longer than the previous answer
            if (crt.size() > ans.size()) {
                ans = crt;  // Store a copy of the current path
            }
        }
    }

    // Reverse the answer vector to maintain the original order
    reverse(ans.begin(), ans.end());

    // Print the length of the longest path found
    cout << ans.size() << endl;

    // Print the elements of the longest path as a space-separated string
    for (size_t i = 0; i < ans.size(); ++i) {
        cout << ans[i];
        if (i < ans.size() - 1) {
            cout << " ";
        }
    }
    cout << endl;

    return 0;
}

// <END-OF-CODE>
