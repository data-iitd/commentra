#include <bits/stdc++.h>

using namespace std;

int main() {
    // Reading the values of n and m from input
    int n, m;
    cin >> n >> m;
    
    // Reading m lists of integers, each containing values after the first element
    vector<vector<int>> li(m);
    for (int i = 0; i < m; i++) {
        li[i].resize(n - 1);
        for (int j = 0; j < n - 1; j++) {
            cin >> li[i][j];
        }
    }
    
    // Reading a tuple p from input
    int p[n - 1];
    for (int i = 0; i < n - 1; i++) {
        cin >> p[i];
    }
    
    // Creating a set q that contains all unique elements from the lists in li
    set<int> q;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n - 1; j++) {
            q.insert(li[i][j]);
        }
    }
    
    // Creating a set r that contains all integers from 1 to n
    set<int> r;
    for (int i = 1; i <= n; i++) {
        r.insert(i);
    }
    
    // Finding the set of values v that are in r but not in q
    set<int> v = r - q;
    
    // Initializing the answer variable to count valid combinations
    int ans = 0;
    
    // Iterating over all possible sizes of combinations from the set q
    for (int i = 0; i <= q.size(); i++) {
        // Generating combinations of size i from the set q
        for (auto s : itertools::combinations(q, i)) {
            // Checking each list in li against the corresponding value in p
            for (int j = 0; j < m; j++) {
                for (int k = 0; k < n - 1; k++) {
                    if (s.count(li[j][k]) % 2!= p[k]) {
                        break;
                    }
                } else {
                    continue;
                }
                break;
            } else {
                // If all checks passed, increment the answer by 2 raised to the power of the size of v
                ans += 1 << v.size();
            }
        }
    }
    
    // Printing the final answer
    cout << ans << endl;
}

