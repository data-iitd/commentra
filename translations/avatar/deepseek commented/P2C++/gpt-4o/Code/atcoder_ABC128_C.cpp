#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    // Read the number of switches (n) and the number of bulbs (m)
    int n, m;
    cin >> n >> m;

    // Read the connections of switches for each bulb and store them in a vector (li)
    vector<vector<int>> li(m);
    for (int i = 0; i < m; ++i) {
        int k;
        cin >> k; // Read the number of switches connected to the bulb
        li[i].resize(k);
        for (int j = 0; j < k; ++j) {
            cin >> li[i][j]; // Read the switch connections
        }
    }

    // Read the pattern of on/off states for each bulb and store it in a vector (p)
    vector<int> p(m);
    for (int i = 0; i < m; ++i) {
        cin >> p[i];
    }

    // Create a set (q) containing all the switches from all the bulbs
    set<int> q;
    for (const auto& switches : li) {
        for (int switch_num : switches) {
            q.insert(switch_num);
        }
    }

    // Create a set (r) containing all the switches from 1 to n
    set<int> r;
    for (int i = 1; i <= n; ++i) {
        r.insert(i);
    }

    // Calculate the set (v) which contains the switches that are not connected to any bulb
    set<int> v;
    for (int i = 1; i <= n; ++i) {
        if (q.find(i) == q.end()) {
            v.insert(i);
        }
    }

    // Initialize the answer variable to count the number of valid configurations
    long long ans = 0;

    // Iterate over all possible combinations of switches from q
    int q_size = q.size();
    for (int i = 0; i <= q_size; ++i) {
        vector<int> combination;
        for (const auto& switch_num : q) {
            combination.push_back(switch_num);
        }
        do {
            // Check if each combination satisfies the given pattern p
            bool valid = true;
            for (int u = 0; u < m; ++u) {
                int count = 0;
                for (int switch_num : li[u]) {
                    if (find(combination.begin(), combination.begin() + i, switch_num) != combination.begin() + i) {
                        count++;
                    }
                }
                if (count % 2 != p[u]) {
                    valid = false;
                    break;
                }
            }
            if (valid) {
                // If a combination satisfies the pattern, increment the answer by 2^len(v)
                ans += pow(2, v.size());
            }
        } while (next_permutation(combination.begin(), combination.end()));
    }

    // Print the total number of valid configurations
    cout << ans << endl;

    return 0;
}

// <END-OF-CODE>
