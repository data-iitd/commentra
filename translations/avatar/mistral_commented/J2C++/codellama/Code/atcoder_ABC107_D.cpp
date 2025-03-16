
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

int main() {
    // Initialize scanner for reading input
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Read the number of elements in the array
    int N;
    cin >> N;

    // Allocate memory for the array
    vector<int> arr(N);

    // Read the elements of the array
    for (int i = 0; i < N; i++) {
        cin >> arr[i]; // Read an element
    }

    // Create an instance of the Task class and call its solve method
    Task tsk;
    cout << tsk.solve(arr) << endl; // Print the result

    return 0;
}

class Task {
    // Method to solve the problem
    public:
        int solve(vector<int> arr) {
            int n = arr.size(); // Number of elements in the array

            // Create a copy of the array for sorting
            vector<int> sorted = arr;
            sort(sorted.begin(), sorted.end()); // Sort the copy in ascending order

            long total = (long) n * (n + 1) / 2; // Calculate the total sum of elements from 1 to n^2

            int l = 0, r = n - 1; // Initialize left and right pointers for binary search

            while (l < r) {
                int mid = l + (r - l) / 2; // Calculate the middle index
                int target = sorted[mid]; // The middle element is the target for this iteration

                int cur = 0; // Initialize current sum
                long cnt = 0; // Initialize count of elements less than or equal to target

                vector<long> bit(2 * n + 2); // Bitmap array for fast counting

                // Initialize the bitmap array
                for (int x = n + 1; x < bit.size(); x += x & -x) {
                    bit[x]++; // Increment the count for the current position
                }

                // Process each element in the original array
                for (int i = 0; i < n; i++) {
                    cur += arr[i] <= target ? 1 : -1; // Increment the current sum if the element is less than or equal to target
                    for (int x = cur + n + 1; x < bit.size(); x += x & -x) {
                        bit[x]++; // Increment the count for the current position
                    }
                    for (int x = cur + n; x > 0; x -= x & -x) {
                        cnt += bit[x]; // Add the count of elements with sum less than or equal to current sum
                    }
                }

                if (cnt >= total / 2 + 1) { // If the count is greater than half the total sum
                    r = mid; // Narrow the search range to the left
                } else {
                    l = mid + 1; // Narrow the search range to the right
                }
            }

            // Return the middle element as the answer
            return sorted[l];
        }
};

