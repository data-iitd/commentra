#include <iostream>
#include <map>

using namespace std;

int main() {
    // Create a variable to read the number of integers to process
    int n;
    cin >> n;

    // Initialize a map to store integers and their counts
    map<int, int> m;

    // Process each integer input
    while (n-- > 0) {
        // Read the next integer
        int num;
        cin >> num;

        // Check if there is no lower key in the map
        auto it = m.lower_bound(num);
        if (it == m.begin()) {
            // If no lower key exists, increment the count for the current number
            m[num]++;
        } else {
            // If there is a lower key, get that key and its count
            --it; // Move to the largest key less than num
            int key = it->first;
            int val = it->second;

            // If the count of the lower key is 1, remove it from the map
            if (val == 1) {
                m.erase(key);
            } else {
                // Otherwise, decrement the count of the lower key
                m[key]--;
            }

            // Increment the count for the current number
            m[num]++;
        }
    }

    // Initialize a variable to hold the final answer
    int ans = 0;

    // Sum up all the counts in the map
    for (const auto& pair : m) {
        ans += pair.second;
    }

    // Print the final answer
    cout << ans << endl;

    return 0;
}
// <END-OF-CODE>
