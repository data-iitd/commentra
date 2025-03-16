#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool check(vector<int>& lis, int k, int mid) {
    // This function checks if it's possible to distribute the elements of lis
    // such that each element is at most mid and the total number of operations
    // does not exceed k.
    for (int i : lis) {
        if (i % mid == 0) {  // If i is divisible by mid, increment k by 1.
            k += 1;
        }
        k -= i / mid;  // Subtract the number of elements that can be handled by mid from k.
    }
    return k >= 0;  // Return true if k is non-negative, else false.
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> lis(n);
    for (int i = 0; i < n; ++i) {
        cin >> lis[i];
    }

    // Initialize the search range with 1 and the maximum value in the list.
    int a = 1, b = *max_element(lis.begin(), lis.end());

    // Initialize the answer with the maximum value in the list.
    int ans = b;

    // Perform a binary search to find the maximum value of mid that satisfies the condition.
    while (a <= b) {
        int mid = (a + b) / 2;  // Calculate the middle value of the current search range.
        if (check(lis, k, mid)) {  // Check if the current mid value is valid.
            ans = mid;  // Update the answer to the current mid value.
            b = mid - 1;  // Adjust the upper bound of the search range.
        } else {
            a = mid + 1;  // Adjust the lower bound of the search range.
        }
    }

    // Print the result, which is the maximum value of mid that satisfies the condition.
    cout << ans << endl;

    return 0;
}
