

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    // Input the number of elements (n) and the position index (k)

    string v;
    cin >> v;
    // Input the string v

    vector<string> d = {"LEFT", "RIGHT"};
    // Define a vector containing the directions "LEFT" and "RIGHT"

    bool f = k - 1 < n - k;
    // Determine the boolean value of f based on the comparison between k-1 and n-k

    int m = min(k - 1, n - k);
    // Assign m as the minimum of k-1 and n-k

    vector<string> a;
    // Initialize an empty vector a to store the sequence of actions

    for (int i = 0; i < m; i++) {
        a.push_back(d[!f]);
        // Append the opposite direction to a based on the value of f
    }

    for (int i = 0; i < v.length(); i++) {
        a.push_back("PRINT " + string(1, v[i]));
        a.push_back(d[f]);
        // Iterate over the string v, appending "PRINT" and the current character, followed by the direction f
    }

    for (int i = a.size() - 1; i >= 0; i--) {
        cout << a[i] << endl;
        // Print all elements in a except the last one, separated by newlines
    }

    return 0;
}
