#include <bits/stdc++.h>

using namespace std;

int main() {
    // Initialize scanner for user input
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cin.exceptions(cin.failbit);
    long long x[3];
    long long max = 0; // Variable to track the maximum size
    
    // Read the sizes of the three lists from user input
    for (int i = 0; i < 3; ++i) {
        cin >> x[i];
        max = max > x[i]? max : x[i]; // Update max if current size is greater
    }
    
    // Read the maximum product limit
    long long k;
    cin >> k;
    
    // Initialize an array of lists to store the elements for each of the three lists
    list<long long> a[3];
    for (int i = 0; i < 3; ++i) {
        a[i] = list<long long>();
    }
    
    // Read the elements for each list and sort them
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < x[i]; ++j) {
            long long tmp;
            cin >> tmp;
            a[i].push_back(tmp); // Add elements to the respective list
        }
        a[i].sort(); // Sort the list after all elements are added
    }
    
    // List to store the valid sums
    list<long long> ans;
    
    // Generate all combinations of elements from the three lists
    for (int i = 0; i < x[0]; ++i) {
        for (int j = 0; j < x[1]; ++j) {
            for (int m = 0; m < x[2]; ++m) {
                // Check if the product of the indices is within the limit k
                if ((i + 1) * (j + 1) * (m + 1) <= k) {
                    // Calculate the sum of the selected elements from each list
                    long long tmp = a[0].back() + a[1].back() + a[2].back();
                    ans.push_back(tmp); // Add the sum to the answer list
                    a[0].pop_back(); // Remove the last element from the list
                    a[1].pop_back(); // Remove the last element from the list
                    a[2].pop_back(); // Remove the last element from the list
                }
            }
        }
    }
    
    // Sort the list of sums in ascending order
    ans.sort();
    
    // Get the size of the answer list
    int n = ans.size();
    
    // Print the largest k sums from the answer list
    for (int i = 0; i < k; ++i) {
        cout << ans.back() << endl; // Print the k largest sums
        ans.pop_back(); // Remove the last element from the list
    }
}

