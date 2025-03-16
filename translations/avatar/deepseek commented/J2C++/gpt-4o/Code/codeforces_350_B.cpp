#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    // Read the number of elements
    int n;
    cin >> n;

    // Initialize vectors to store the input values
    vector<int> a(n + 1);
    vector<int> b(n + 1);
    vector<int> num(n + 1, 0);

    // Read the elements of array a
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    // Read the elements of array b
    for (int i = 1; i <= n; i++)
        cin >> b[i];

    // Count the occurrences of each element in array b
    for (int i = 1; i <= n; i++)
        num[b[i]]++;

    // Initialize variables to store the result
    string ss = "";
    int ans = 0;
    vector<bool> st(n + 1, false);

    // Iterate through the elements of array a
    for (int i = 1; i <= n; i++) {
        if (a[i] == 1) {
            // Mark the current element as visited
            st[i] = true;

            // Build the sequence of indices
            string sb = "";
            int x = b[i];
            string sss = to_string(i);
            sb += " " + string(sss.rbegin(), sss.rend());
            int s = 1;

            // Continue building the sequence until a visited element or mismatch is found
            while (!st[x] && num[x] == 1 && x != 0 && a[x] != 1) {
                sss = to_string(x);
                sb += " " + string(sss.rbegin(), sss.rend());
                st[x] = true;
                x = b[x];
                s++;
            }

            // Update the result if a longer sequence is found
            if (s > ans) {
                ans = s;
                ss = string(sb.rbegin(), sb.rend());
            }
        }
    }

    // Print the result
    cout << ans << endl;
    cout << ss << endl;

    return 0;
}
// <END-OF-CODE>
