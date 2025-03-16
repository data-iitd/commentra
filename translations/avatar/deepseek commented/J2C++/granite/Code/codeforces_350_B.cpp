
#include <bits/stdc++.h>
using namespace std;

int main() {
    // Read the number of elements
    int n;
    cin >> n;

    // Initialize arrays to store the input values
    int a[n + 1], b[n + 1], num[n + 1];

    // Read the elements of array a
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    // Read the elements of array b
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }

    // Count the occurrences of each element in array b
    for (int i = 1; i <= n; i++) {
        num[b[i]]++;
    }

    // Initialize variables to store the result
    string ss = "";
    int ans = 0;
    bool st[n + 1];

    // Iterate through the elements of array a
    for (int i = 1; i <= n; i++) {
        if (a[i] == 1) {
            // Mark the current element as visited
            st[i] = true;

            // Build the sequence of indices
            stringstream sb;
            int x = b[i];
            stringstream sss;
            sss << i;
            sb << " " << sss.str();
            int s = 1;

            // Continue building the sequence until a visited element or mismatch is found
            while (!st[x] && num[x] == 1 && x!= 0 && a[x]!= 1) {
                sss = stringstream();
                sss << x;
                sb << " " << sss.str();
                st[x] = true;
                x = b[x];
                s++;
            }

            // Update the result if a longer sequence is found
            if (s > ans) {
                ans = s;
                ss = sb.str();
            }
        }
    }

    // Print the result
    cout << ans << endl;
    cout << ss << endl;

    return 0;
}
