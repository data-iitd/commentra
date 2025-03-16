#include <bits/stdc++.h>

using namespace std;

class Main {
private:
    int n;
    int *a;
    map<int, int> s;

public:
    Main() {
        // Read input values and initialize variables
        cin >> n;
        a = new int[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
    }

    ~Main() {
        delete[] a;
    }

    void solve() {
        // Main logic to find the maximum k using binary search
        int ng = 0; // Lower bound for binary search
        int ok = n; // Upper bound for binary search

        // Perform binary search to find the maximum k
        while (ok - ng > 1) {
            int k = (ng + ok) / 2; // Calculate mid-point
            // Check if it is possible to achieve the current k
            if (isPossible(k)) {
                ok = k; // If possible, adjust upper bound
            } else {
                ng = k; // If not possible, adjust lower bound
            }
        }
        // Output the result
        cout << ok << endl;
    }

    bool isPossible(int k) {
        // Check if it is possible to achieve the given k
        s.clear(); // Clear the map for new calculations
        int current = 0; // Initialize current value

        // Iterate through each element in the array
        for (int i = 0; i < n; i++) {
            // If the current element is less than or equal to the current value
            if (a[i] <= current) {
                // If k is 1, return false as we cannot have duplicates
                if (k == 1) return false;

                // Remove elements from map that are greater than or equal to ai
                while (!s.empty() && s.rbegin()->first >= a[i]) {
                    s.erase(s.rbegin()->first); // Remove the last entry
                }

                int p = a[i] - 1; // Start checking from the previous number
                while (true) {
                    // If p is less than 0, return false
                    if (p < 0) return false;

                    // Get the count of p from map and increment it
                    int sp = s[p] + 1;
                    s[p] = sp; // Update the map with the new count

                    // If the count reaches k, remove p from map and decrement p
                    if (sp == k) {
                        s.erase(p);
                        p--;
                    } else {
                        break; // Exit the loop if count is less than k
                    }
                }
            }
            current = a[i]; // Update current to the current element
        }
        return true; // Return true if the condition is satisfied
    }
};

int main() {
    Main m;
    m.solve();
    return 0;
}

