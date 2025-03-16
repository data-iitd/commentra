#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

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
    int p[m];
    for (int i = 0; i < m; i++) {
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
    for (int i = 1; i <= n; i++) {
        r.insert(i);
    }

    // Find the set of numbers in r that are not in q
    set<int> v = r - q;

    // Initialize answer to 0
    int ans = 0;

    // Iterate through all possible subsets of q, from empty to the full set
    for (int i = 0; i <= q.size(); i++) {
        // Iterate through all combinations of i elements from q
        for (set<int> s : {set<int>(s) for s in itertools::combinations(q, i)}) {
            // Iterate through each list and pattern
            for (int j = 0; j < m; j++) {
                for (int k = 0; k < li[j].size(); k++) {
                    // Convert s to a set
                    set<int> t = s;
                    // Check if the current combination of lists and pattern match the current subset of q
                    if (t.count(li[j][k]) % 2!= p[j]) {
                        // If not, break out of the inner loop and move on to the next combination
                        break;
                    }
                }
            }
            // If all combinations of lists and pattern match the current subset of q, increment the answer
            else {
                ans += 1 << v.size();
            }
        }
    }

    // Print the answer
    cout << ans << endl;
}

