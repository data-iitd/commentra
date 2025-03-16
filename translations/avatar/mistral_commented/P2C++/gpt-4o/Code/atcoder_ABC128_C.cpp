#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <iterator>
#include <cmath>

using namespace std;

// Function to calculate the power of 2
long long power_of_2(int exp) {
    return 1LL << exp; // 2^exp
}

// Define the main function
int main() {
    // Read input: number of test cases, number of lists, and the lists themselves
    int n, m;
    cin >> n >> m;
    vector<vector<int>> li(m);
    for (int i = 0; i < m; ++i) {
        int size;
        cin >> size;
        li[i].resize(size - 1);
        for (int j = 0; j < size - 1; ++j) {
            cin >> li[i][j];
        }
    }

    // Read input: pattern
    vector<int> p(m);
    for (int i = 0; i < m; ++i) {
        cin >> p[i];
    }

    // Create a set of all elements in the lists
    set<int> q;
    for (const auto& list : li) {
        q.insert(list.begin(), list.end());
    }

    // Create a set of numbers from 1 to n (excluding n)
    set<int> r;
    for (int i = 1; i <= n; ++i) {
        r.insert(i);
    }

    // Find the set of numbers in r that are not in q
    set<int> v;
    for (int num : r) {
        if (q.find(num) == q.end()) {
            v.insert(num);
        }
    }

    // Initialize answer to 0
    long long ans = 0;

    // Iterate through all possible subsets of q
    int q_size = q.size();
    vector<int> q_vector(q.begin(), q.end());
    for (int i = 0; i < (1 << q_size); ++i) {
        set<int> s;
        for (int j = 0; j < q_size; ++j) {
            if (i & (1 << j)) {
                s.insert(q_vector[j]);
            }
        }

        // Check if the current combination of lists and pattern match the current subset of q
        bool valid = true;
        for (int u = 0; u < m; ++u) {
            int count = 0;
            for (int num : li[u]) {
                if (s.find(num) != s.end()) {
                    count++;
                }
            }
            if (count % 2 != p[u]) {
                valid = false;
                break;
            }
        }

        // If all combinations of lists and pattern match the current subset of q, increment the answer
        if (valid) {
            ans += power_of_2(v.size());
        }
    }

    // Print the answer
    cout << ans << endl;

    return 0;
}

// <END-OF-CODE>
