#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Take the number of test cases as input
    int n;
    cin >> n;

    // Initialize a vector 't' with 0 as the first element and followed by the given input list
    vector<int> t(n + 1);
    t[0] = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> t[i];
    }

    // Initialize a vector 'a' with 0 as the first element and followed by the given input list
    vector<int> a(n + 1);
    a[0] = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    // Initialize empty vector 'ans' and a count vector 'cnt'
    vector<int> ans;
    vector<int> cnt(n + 1, 0);

    // Iterate through each element in vector 'a' and increment the count of its corresponding index in vector 'cnt'
    for (int i = 1; i <= n; ++i) {
        cnt[a[i]]++;
    }

    // Iterate through each index from 1 to n
    for (int i = 1; i <= n; ++i) {
        // If the current index in vector 't' is 1
        if (t[i] == 1) {
            // Initialize an empty vector 'crt' to store the current sequence
            vector<int> crt;
            crt.push_back(i);
            // Get the current element in vector 'a'
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

    // Reverse the order of elements in the answer sequence
    reverse(ans.begin(), ans.end());

    // Print the length of the answer sequence
    cout << ans.size() << endl;
    // Print the answer sequence with each element separated by a space
    for (size_t i = 0; i < ans.size(); ++i) {
        if (i > 0) cout << " ";
        cout << ans[i];
    }
    cout << endl;

    return 0;
}
// <END-OF-CODE>
