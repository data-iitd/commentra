
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Create a Scanner object to read input from the user
    // Read the number of elements (n), number of selected elements (k), 
    // lower bound (l), upper bound (r), total sum (sAll), and sum of selected elements (sk)
    int n, k, l, r, sAll, sk;
    cin >> n >> k >> l >> r >> sAll >> sk;

    // Call the getPoints method to calculate the points distribution
    vector<int> ans = getPoints(n, k, l, r, sAll, sk);

    // Print the resulting points distribution
    for (int num : ans) {
        cout << num << " ";
    }

    return 0;
}

vector<int> getPoints(int n, int k, int l, int r, int sAll, int sk) {
    // Initialize an array to hold the points for each element
    vector<int> ans(n, l);

    // Fill the array with the minimum value l
    // Adjust the total sum by subtracting the sum of selected elements and the minimum values
    // Adjust the sum of selected elements by subtracting the minimum values
    // Distribute the remaining points to the last k elements
    // Distribute the remaining total sum to the first n-k elements

    // Return the final points distribution
    return ans;
}

