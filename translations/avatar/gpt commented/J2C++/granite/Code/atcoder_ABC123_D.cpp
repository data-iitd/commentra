
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Initialize scanner for user input
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    // Create an array to store the sizes of three lists
    int x[3];
    int max = 0; // Variable to track the maximum size
    
    // Read the sizes of the three lists from user input
    for (int i = 0; i < 3; ++i) {
        cin >> x[i];
        max = max(max, x[i]); // Update max if current size is greater
    }
    
    // Read the maximum product limit
    int k;
    cin >> k;
    
    // Initialize an array of lists to store the elements for each of the three lists
    vector<long long> a[3];
    for (int i = 0; i < 3; ++i) {
        a[i].resize(x[i]);
    }
    
    // Read the elements for each list and sort them
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < x[i]; ++j) {
            cin >> a[i][j]; // Add elements to the respective list
        }
        sort(a[i].begin(), a[i].end()); // Sort the list after all elements are added
    }
    
    // List to store the valid sums
    vector<long long> ans;
    
    // Generate all combinations of elements from the three lists
    for (int i = 0; i < x[0]; ++i) {
        for (int j = 0; j < x[1]; ++j) {
            for (int m = 0; m < x[2]; ++m) {
                // Check if the product of the indices is within the limit k
                if ((i + 1) * (j + 1) * (m + 1) <= k) {
                    // Calculate the sum of the selected elements from each list
                    long long tmp = a[0][x[0] - i - 1] + a[1][x[1] - j - 1] + a[2][x[2] - m - 1];
                    ans.push_back(tmp); // Add the sum to the answer list
                }
            }
        }
    }
    
    // Sort the list of sums in ascending order
    sort(ans.begin(), ans.end());
    
    // Get the size of the answer list
    int n = ans.size();
    
    // Print the largest k sums from the answer list
    for (int i = 0; i < k; ++i) {
        cout << ans[n - i - 1] << endl; // Print the k largest sums
    }
    
    return 0;
}

