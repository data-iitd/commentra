
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> ara(n);
    map<int, int> map;

    // Populate the array and the map with element counts
    for (int i = 0; i < n; i++) {
        int v;
        cin >> v;
        ara[i] = v;
        if (map.find(v) == map.end()) {
            map[v] = 1; // Initialize count for new element
        } else {
            map[v]++; // Increment count for existing element
        }
    }

    int max = 0; // Initialize max to track the highest frequency
    // Find the maximum frequency in the map
    for (auto i : map) {
        max = max(max, i.second);
    }

    map<int, int> mm; // HashMap to track occurrences as elements appear
    // Find the most frequent element
    for (int i = 0; i < n; i++) {
        if (mm.find(ara[i]) == mm.end()) {
            mm[ara[i]] = 1; // Initialize count for new element
            if (mm[ara[i]] == max) {
                cout << ara[i] << endl; // Print the most frequent element
                break; // Exit the loop after finding the most frequent element
            }
        } else {
            mm[ara[i]]++; // Increment count for existing element
            if (mm[ara[i]] == max) {
                cout << ara[i] << endl; // Print the most frequent element
                break; // Exit the loop after finding the most frequent element
            }
        }
    }

    return 0;
}

