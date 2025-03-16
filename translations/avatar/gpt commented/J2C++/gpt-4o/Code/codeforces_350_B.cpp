#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    // Initialize a scanner for input
    int n;
    cin >> n;

    // Initialize vectors to store input values and counts
    vector<int> a(n + 1);
    vector<int> b(n + 1);
    vector<int> num(n + 1, 0);

    // Read values into vector a
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    // Read values into vector b
    for (int i = 1; i <= n; i++)
        cin >> b[i];

    // Count occurrences of each value in vector b
    for (int i = 1; i <= n; i++)
        num[b[i]]++;

    // Initialize variables for tracking the longest sequence and its representation
    string ss = "";
    int ans = 0;
    vector<bool> st(n + 1, false);

    // Iterate through each element to find the longest valid sequence
    for (int i = 1; i <= n; i++) {
        // Check if the current element in a is 1
        if (a[i] == 1) {
            st[i] = true; // Mark this index as visited
            string sb = "";
            int x = b[i]; // Start with the corresponding value in b
            string sss = to_string(i); // Append the current index
            sb += " " + string(sss.rbegin(), sss.rend()); // Reverse and append to the sequence

            int s = 1; // Initialize the length of the current sequence

            // Continue to build the sequence while conditions are met
            while (!st[x] && num[x] == 1 && x != 0 && a[x] != 1) {
                sss = to_string(x); // Append the next index
                sb += " " + string(sss.rbegin(), sss.rend()); // Reverse and append to the sequence
                st[x] = true; // Mark this index as visited
                x = b[x]; // Move to the next index in b
                s++; // Increment the sequence length
            }

            // Update the longest sequence found if the current one is longer
            if (s > ans) {
                ans = s;
                ss = string(sb.rbegin(), sb.rend()); // Store the longest sequence
            }
        }
    }

    // Output the length of the longest sequence and the sequence itself
    cout << ans << endl;
    cout << ss << endl;

    return 0;
}

// <END-OF-CODE>
