#include <bits/stdc++.h>
using namespace std;

int main() {
    // Create a Scanner object to read input from the user
    cin >> noskipws;
    cin.tie(0);
    cin.sync_with_stdio(false);
    Scanner scan;
    scan = Scanner(cin);
    
    // Read the number of elements (n), number of selected elements (k), 
    // lower bound (l), upper bound (r), total sum (sAll), and sum of selected elements (sk)
    int n, k, l, r, sAll, sk;
    scan >> n >> k >> l >> r >> sAll >> sk;
    
    // Call the getPoints method to calculate the points distribution
    int ans[n];
    ans = getPoints(n, k, l, r, sAll, sk);
    
    // Print the resulting points distribution
    for (int num : ans) {
        cout << num << " ";
    }
}

int* getPoints(int n, int k, int l, int r, int sAll, int sk) {
    // Initialize an array to hold the points for each element
    int* ans = new int[n];
    
    // Fill the array with the minimum value l
    fill_n(ans, n, l);
    
    // Adjust the total sum by subtracting the sum of selected elements and the minimum values
    sAll -= sk + (n - k) * l;
    
    // Adjust the sum of selected elements by subtracting the minimum values
    sk -= k * l;
    
    // Distribute the remaining points to the last k elements
    while (sk > 0) {
        int idx = n - 1;
        while (sk > 0 && idx >= n - k) {
            ans[idx--]++; // Increment the points for the selected elements
            sk--; // Decrease the remaining points to distribute
        }
    }
    
    // Distribute the remaining total sum to the first n-k elements
    while (sAll > 0) {
        int idx = 0;
        while (sAll > 0 && idx < n - k) {
            ans[idx]++; // Increment the points for the non-selected elements
            sAll--; // Decrease the remaining total sum to distribute
        }
    }
    
    // Return the final points distribution
    return ans;
}

