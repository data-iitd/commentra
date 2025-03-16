
#include <bits/stdc++.h>
using namespace std;

int main() {
    // Importing the itertools module for combinatorial functions
    #include <itertools>
    
    // Reading the values of n and m from input
    int n, m;
    cin >> n >> m;
    
    // Reading m lists of integers, each containing values after the first element
    vector<vector<int>> li(m);
    for (int i = 0; i < m; i++) {
        int k;
        cin >> k;
        li[i].resize(k);
        for (int j = 1; j < k; j++) {
            cin >> li[i][j];
        }
    }
    
    // Reading a tuple p from input
    vector<int> p(m);
    for (int i = 0; i < m; i++) {
        cin >> p[i];
    }
    
    // Creating a set q that contains all unique elements from the lists in li
    set<int> q;
    for (int i = 0; i < m; i++) {
        for (int j = 1; j < li[i].size(); j++) {
            q.insert(li[i][j]);
        }
    }
    
    // Creating a set r that contains all integers from 1 to n
    set<int> r;
    for (int i = 1; i <= n; i++) {
        r.insert(i);
    }
    
    // Finding the set of values v that are in r but not in q
    set<int> v;
    set_difference(r.begin(), r.end(), q.begin(), q.end(), inserter(v, v.begin()));
    
    // Initializing the answer variable to count valid combinations
    int ans = 0;
    
    // Iterating over all possible sizes of combinations from the set q
    for (int i = 0; i <= q.size(); i++) {
        // Generating combinations of size i from the set q
        vector<int> s(q.begin(), q.end());
        itertools::combinations(s, i);
        do {
            // Checking each list in li against the corresponding value in p
            bool valid = true;
            for (int j = 0; j < m; j++) {
                set<int> t(s.begin(), s.end());
                int count = 0;
                for (int k = 1; k < li[j].size(); k++) {
                    if (t.count(li[j][k])) {
                        count++;
                    }
                }
                if (count % 2!= p[j]) {
                    valid = false;
                    break;
                }
            }
            if (valid) {
                // If all checks passed, increment the answer by 2 raised to the power of the size of v
                ans += pow(2, v.size());
            }
        } while (next_permutation(s.begin(), s.end()));
    }
    
    // Printing the final answer
    cout << ans << endl;
    
    return 0;
}

