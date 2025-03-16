#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
    int n; // Number of elements
    cin >> n; // Read the number of elements
    vector<int> ara(n); // Initialize array to store elements
    map<int, int> map; // HashMap to count occurrences of each element

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

