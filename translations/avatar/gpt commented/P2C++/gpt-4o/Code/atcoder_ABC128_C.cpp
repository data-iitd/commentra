#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <iterator>
#include <cmath>
#include <tuple>

using namespace std;

int main() {
    // Reading the values of n and m from input
    int n, m;
    cin >> n >> m;

    // Reading m lists of integers, each containing values after the first element
    vector<vector<int>> li(m);
    for (int i = 0; i < m; ++i) {
        int size;
        cin >> size; // Read the size of the list
        li[i].resize(size);
        for (int j = 0; j < size; ++j) {
            cin >> li[i][j];
        }
    }

    // Reading a tuple p from input
    vector<int> p(m);
    for (int i = 0; i < m; ++i) {
        cin >> p[i];
    }

    // Creating a set q that contains all unique elements from the lists in li
    set<int> q;
    for (const auto& list : li) {
        q.insert(list.begin(), list.end());
    }

    // Creating a set r that contains all integers from 1 to n
    set<int> r;
    for (int i = 1; i <= n; ++i) {
        r.insert(i);
    }

    // Finding the set of values v that are in r but not in q
    set<int> v;
    set_difference(r.begin(), r.end(), q.begin(), q.end(), inserter(v, v.end()));

    // Initializing the answer variable to count valid combinations
    long long ans = 0;

    // Iterating over all possible sizes of combinations from the set q
    for (int i = 0; i <= q.size(); ++i) {
        vector<int> combination;
        // Generate combinations of size i from the set q
        for (const auto& elem : q) {
            combination.push_back(elem);
        }
        do {
            // Check each list in li against the corresponding value in p
            bool valid = true;
            for (int j = 0; j < m; ++j) {
                int count = 0;
                for (const auto& u : li[j]) {
                    if (find(combination.begin(), combination.end(), u) != combination.end()) {
                        count++;
                    }
                }
                if (count % 2 != p[j]) {
                    valid = false;
                    break;
                }
            }
            if (valid) {
                // If all checks passed, increment the answer by 2 raised to the power of the size of v
                ans += pow(2, v.size());
            }
        } while (next_permutation(combination.begin(), combination.end()));
    }

    // Printing the final answer
    cout << ans << endl;

    return 0;
}

// <END-OF-CODE>
