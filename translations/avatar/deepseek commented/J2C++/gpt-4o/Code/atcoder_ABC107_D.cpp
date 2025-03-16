#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Task {
public:
    int solve(vector<int>& arr) {
        int n = arr.size();
        vector<int> sorted = arr; // Create a copy of the array
        sort(sorted.begin(), sorted.end()); // Sort the array

        long total = (long)n * (n + 1) / 2; // Calculate the total number of elements
        int l = 0, r = n - 1;

        // Implement binary search to find the median
        while (l < r) {
            int mid = l + (r - l) / 2;
            int target = sorted[mid];
            int cur = 0;
            long cnt = 0;
            vector<long> bit(2 * n + 2, 0); // Initialize the binary indexed tree

            for (int x = n + 1; x < bit.size(); x += x & -x)
                bit[x]++; // Initialize the binary indexed tree

            for (int i = 0; i < n; i++) {
                cur += arr[i] <= target ? 1 : -1;
                for (int x = cur + n + 1; x < bit.size(); x += x & -x)
                    bit[x]++; // Update the binary indexed tree
                for (int x = cur + n; x > 0; x -= x & -x)
                    cnt += bit[x]; // Calculate the count of elements less than or equal to the target
            }

            if (cnt >= total / 2 + 1)
                r = mid; // Adjust the search range if the count is sufficient
            else
                l = mid + 1;
        }

        return sorted[l]; // Return the median value
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N; // Read the size of the array
    vector<int> arr(N);
    for (int i = 0; i < N; i++)
        cin >> arr[i]; // Read the array elements

    Task tsk;
    cout << tsk.solve(arr) << endl; // Print the result of the solve method

    return 0;
}

// <END-OF-CODE>
