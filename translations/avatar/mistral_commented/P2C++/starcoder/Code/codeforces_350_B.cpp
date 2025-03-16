#include <bits/stdc++.h>
using namespace std;

int main() {
    // Take the number of test cases as input
    int n;
    cin >> n;

    // Initialize a list 't' with 0 as the first element and followed by the given input list
    vector<int> t(n+1);
    t[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> t[i];
    }

    // Initialize a list 'a' with 0 as the first element and followed by the given input list
    vector<int> a(n+1);
    a[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    // Initialize empty lists 'ans' and 'cnt'
    vector<int> ans;
    vector<int> cnt(n+1, 0);

    // Iterate through each element in list 'a' and increment the count of its corresponding index in list 'cnt'
    for (int i = 1; i <= n; i++) {
        cnt[a[i]]++;
    }

    // Iterate through each index from 1 to n
    for (int i = 1; i <= n; i++) {
        // If the current index in list 't' is 1
        if (t[i] == 1) {
            // Initialize an empty list 'crt' to store the current sequence
            vector<int> crt;
            // Get the current element in list 'a'
            int x = a[i];
            // Continue adding elements to 'crt' as long as the corresponding index in 'cnt' has a count of 1
            while (cnt[x] == 1) {
                crt.push_back(x);
                x = a[x];
            }
            // If the length of the current sequence is greater than the length of the current answer sequence
            if (crt.size() > ans.size()) {
                // Update the answer sequence with the current sequence
                ans = crt;
            }
        }
    }

    // Print the length of the answer sequence
    cout << ans.size() << endl;
    // Print the answer sequence with each element separated by a space
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    return 0;
}

