#include <bits/stdc++.h>

using namespace std;

int main() {
    // Read an integer n from the standard input
    int n;
    cin >> n;

    // Create a list a of size n by reading n integers from the standard input and applying the map() function to convert each input integer to an integer
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Initialize two variables, pre and ans, to float('inf') and 0, respectively
    int pre = INT_MAX;
    int ans = 0;

    // Sort the list a in descending order using the sort() method
    sort(a.begin(), a.end(), greater<int>());

    // Iterate through the list a using a for loop
    for (int j = 0; j < n; j++) {
        // Calculate the maximum of 0 and the minimum of pre - 1 and a[j]. This value is added to ans.
        ans += max(0, min(pre - 1, a[j]));

        // Update the value of pre to be the minimum of pre - 1 and a[j].
        pre = min(pre - 1, a[j]);
    }

    // After the loop, print the value of ans.
    cout << ans << endl;

    return 0;
}

