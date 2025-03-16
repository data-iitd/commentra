#include <bits/stdc++.h>
using namespace std;

int main() {
    // Read the number of elements
    int n; cin >> n;

    // Read the list 't' and prepend a 0 for 1-based indexing
    vector<int> t(n + 1);
    for (int i = 1; i <= n; i++) cin >> t[i];

    // Read the list 'a' and prepend a 0 for 1-based indexing
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    // Initialize the answer list and a count list to track occurrences
    vector<int> ans, cnt(n + 1);

    // Count the occurrences of each element in list 'a'
    for (int i = 1; i <= n; i++) cnt[a[i]]++;

    // Iterate through each index from 1 to n
    for (int i = 1; i <= n; i++) {
        // Check if the current element in 't' is 1
        if (t[i] == 1) {
            // Initialize a current path list starting with the current index
            vector<int> crt = {i};
            // Set x to the corresponding value in 'a'
            int x = a[i];

            // Continue to follow the chain while the count of x is 1
            while (cnt[x] == 1) {
                crt.push_back(x);  // Add x to the current path
                x = a[x];  // Move to the next index in the chain
            }

            // Update the answer if the current path is longer than the previous answer
            if (crt.size() > ans.size()) ans = crt;
        }
    }

    // Print the length of the longest path found
    cout << ans.size() << endl;

    // Print the elements of the longest path as a space-separated string
    for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
    cout << endl;

    return 0;
}

