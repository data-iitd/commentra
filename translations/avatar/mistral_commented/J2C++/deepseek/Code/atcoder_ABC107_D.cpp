#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric> // For std::accumulate

class Task {
public:
    int solve(std::vector<int>& arr) {
        int n = arr.size(); // Number of elements in the array

        // Create a copy of the array for sorting
        std::vector<int> sorted = arr;
        std::sort(sorted.begin(), sorted.end()); // Sort the copy in ascending order

        long long total = static_cast<long long>(n) * (n + 1) / 2; // Calculate the total sum of elements from 1 to n^2

        int l = 0, r = n - 1; // Initialize left and right pointers for binary search

        while (l < r) {
            int mid = l + (r - l) / 2; // Calculate the middle index
            int target = sorted[mid]; // The middle element is the target for this iteration

            long long cur = 0; // Initialize current sum
            long long cnt = 0; // Initialize count of elements less than or equal to target

            std::vector<long long> bit(2 * n + 2, 0); // Bitmap array for fast counting

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

int main() {
    int N;
    std::cin >> N;

    std::vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        std::cin >> arr[i]; // Read an element
    }

    // Create an instance of the Task class and call its solve method
    Task tsk;
    std::cout << tsk.solve(arr) << std::endl; // Print the result

    return 0;
}

