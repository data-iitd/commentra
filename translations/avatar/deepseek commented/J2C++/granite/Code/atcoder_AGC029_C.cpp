

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Main {
private:
    int n; // Number of elements in the array
    vector <int> a; // The array itself
    map <int, int> s; // Map to keep track of counts of elements

public:
    Main() {}

    void set() {
        cin >> n;
        a.resize(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        s.clear();
    }

    void solve() {
        set();
        int ng = 0; // Lower bound for binary search
        int ok = n; // Upper bound for binary search
        while (ok - ng > 1) {
            int k = (ng + ok) / 2; // Midpoint of the current search range
            if (isPossible(k)) {
                ok = k; // Adjust the upper bound if k is possible
            } else {
                ng = k; // Adjust the lower bound if k is not possible
            }
        }
        cout << ok << endl; // Print the result of the binary search
    }

    bool isPossible(int k) {
        s.clear(); // Clear the map for each new k
        int current = 0; // Current index in the array
        for (int ai : a) {
            if (ai <= current) { // Check if the current element can be part of the previous subarray
                if (k == 1) return false; // If k is 1, it's not possible to partition
                auto it = s.upper_bound(ai); // Get an iterator to the element just before ai
                while (it!= s.end()) { // Remove elements from the map that are greater than or equal to the current element
                    if (it->first >= ai) {
                        s.erase(it);
                    } else {
                        break;
                    }
                    it = s.upper_bound(ai);
                }
                int p = ai - 1; // Start checking from the previous element
                while (true) {
                    if (p < 0) return false; // If p goes below 0, it's not possible to partition
                    auto it = s.find(p); // Get an iterator to the element p
                    if (it!= s.end()) { // If p exists in the map
                        it->second++; // Increment the count of p
                    } else {
                        s[p] = 1; // Add p to the map with a count of 1
                    }
                    if (s[p] == k) { // If the count of p is equal to k
                        s.erase(p); // Remove p from the map
                        p--; // Move to the previous element
                    } else {
                        break; // Break the loop if the count is not equal to k
                    }
                }
            }
            current = ai; // Update the current element
        }
        return true; // Return true if it's possible to partition the array into k subarrays
    }
};

int main() {
    Main m;
    m.solve();
    return 0;
}

