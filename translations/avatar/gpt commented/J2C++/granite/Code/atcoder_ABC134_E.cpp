
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    // Create a map to store integers and their counts
    map<int, int> map;

    // Read the number of integers to process
    int n;
    cin >> n;

    // Process each integer input
    while (n-- > 0) {
        // Read the next integer
        int num;
        cin >> num;

        // Check if there is no lower key in the map
        auto it = map.lower_bound(num);
        if (it == map.begin()) {
            // If no lower key exists, increment the count for the current number
            int val = map[num];
            map[num] = ++val;
        } else {
            // If there is a lower key, get that key and its count
            --it;
            int key = it->first;
            int val = it->second;

            // If the count of the lower key is 1, remove it from the map
            if (val == 1) {
                map.erase(key);
            } else {
                // Otherwise, decrement the count of the lower key
                map[key] = --val;
            }

            // Increment the count for the current number
            val = map[num];
            map[num] = ++val;
        }
    }

    // Initialize a variable to hold the final answer
    int ans = 0;

    // Sum up all the counts in the map
    for (auto it = map.begin(); it!= map.end(); ++it) {
        int val = it->second;
        ans += val;
    }

    // Print the final answer
    cout << ans << endl;

    return 0;
}
