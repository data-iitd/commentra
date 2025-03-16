#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <iterator>
#include <cmath>

using namespace std;

// Define the main function
int main() {
    // Read input: number of test cases, number of lists, and the lists themselves
    int n, m;
    cin >> n >> m;
    vector<vector<int>> li(m);
    for (int i = 0; i < m; i++) {
        int k;
        cin >> k;
        li[i].resize(k);
        for (int j = 0; j < k; j++) {
            cin >> li[i][j];
        }
    }

    // Read input: pattern
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    // Create a set of all elements in the lists
    set<int> q;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < li[i].size(); j++) {
            q.insert(li[i][j]);
        }
    }

    // Create a set of numbers from 1 to n (excluding n)
    set<int> r;
    for (int i = 1; i < n+1; i++) {
        r.insert(i);
    }

    // Find the set of numbers in r that are not in q
    set<int> v;
    set_difference(r.begin(), r.end(), q.begin(), q.end(), inserter(v, v.begin()));

    // Initialize answer to 0
    long long ans = 0;

    // Iterate through all possible subsets of q, from empty to the full set
    for (int i = 0; i < pow(2, q.size()); i++) {
        // Iterate through all combinations of i elements from q
        for (int j = 0; j < pow(2, i); j++) {
            // Iterate through each list and pattern
            for (int k = 0; k < m; k++) {
                // Convert s to a set
                set<int> s;
                for (int l = 0; l < i; l++) {
                    if (j & (1 << l)) {
                        s.insert(li[k][l]);
                    }
                }
                // Check if the current combination of lists and pattern match the current subset of q
                if (s.size() % 2 != p[k]) {
                    // If not, break out of the inner loop and move on to the next combination
                    break;
                }
            }
            // If all combinations of lists and pattern match the current subset of q, increment the answer
            if (k == m) {
                ans += pow(2, v.size());
            }
        }
    }

    // Print the answer
    cout << ans << endl;

    return 0;
}

// 