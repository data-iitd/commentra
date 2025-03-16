
#include <iostream>
#include <vector>

using namespace std;

bool check(vector<int> lis, int k, int mid) {
    // Initialize a loop to iterate through each element in the list
    for (int i : lis) {
        // If the current element is divisible by mid, increment k
        if (i % mid == 0) {
            k += 1;
        }
        // Decrease k by the number of times mid fits into the current element
        k -= (i / mid);
    }
    // Return True if k is non-negative, indicating the condition is satisfied
    return k >= 0;
}

int main() {
    // Read input values for n (number of elements) and k (threshold value)
    int n, k;
    cin >> n >> k;
    // Read the list of integers
    vector<int> lis(n);
    for (int i = 0; i < n; i++) {
        cin >> lis[i];
    }

    // Initialize the binary search bounds
    int a = 1, b = *max_element(lis.begin(), lis.end());
    // Set the initial answer to the maximum value in the list
    int ans = b;

    // Perform binary search to find the optimal mid value
    while (a <= b) {
        // Calculate the mid value
        int mid = (a + b) / 2;
        // Check if the current mid value satisfies the condition using the check function
        if (check(lis, k, mid)) {
            // If it does, update the answer and narrow the search to the left half
            ans = mid;
            b = mid - 1;
        } else {
            // If it doesn't, narrow the search to the right half
            a = mid + 1;
        }
    }

    // Print the final answer
    cout << ans << endl;

    return 0;
}

