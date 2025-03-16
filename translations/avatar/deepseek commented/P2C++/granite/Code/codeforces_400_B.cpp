

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    // Read the dimensions of the grid (n: number of rows, m: number of columns)

    set<int> c;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        // Read the string for each row

        c.insert(s.find("S") - s.find("G"));
        // Find the index of 'S' and 'G' in the string and calculate the difference.
        // Insert the difference into the set 'c'.
    }

    if (any_of(c.begin(), c.end(), [](int a) { return a < 0; })) {
        cout << -1 << endl;
        // Check if there is any negative difference in the set 'c'.
        // If there is, print '-1'.
    } else {
        cout << c.size() << endl;
        // If there is no negative difference, print the number of unique non-negative differences in the set 'c'.
    }

    return 0;
}
