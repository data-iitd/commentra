
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Read input from the user
    int N;
    cin >> N;

    // Parse the input into a list of integers
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    // Filter the list to keep only non-increasing elements
    vector<int> B;
    B.push_back(A[0]);
    for (int i = 1; i < N; i++) {
        if (A[i] <= A[i - 1]) {
            B.push_back(A[i]);
        }
    }

    // Get the length of the filtered list
    N = B.size();

    // Function to cut the array based on a given index
    auto cut = [&](vector<pair<int, int>>& array, int index) {
        // If the index is less than 1, return an empty list
        if (index < 1) {
            return vector<pair<int, int>>();
        }

        // If the index is less than or equal to the first element, return it with the first element's second value
        if (index <= array[0].first) {
            return vector<pair<int, int>>({{index, array[0].second}});
        }

        // Iterate backwards through the array to find the appropriate cut point
        for (int i = array.size() - 1; i > 0; i--) {
            if (array[i - 1].first < index) {
                return vector<pair<int, int>>(array.begin(), array.begin() + i) + vector<pair<int, int>>({{index, array[i].second}});
            }
        }
    };

    // Function to check if a certain condition is possible with K
    auto is_possible = [&](int K) {
        // Initialize the dynamic programming array with the first element
        vector<pair<int, int>> dp = {{B[0], 0}};

        // Iterate through the remaining elements in B
        for (int i = 1; i < N; i++) {
            // If the current element is less than or equal to the last element in dp, cut dp
            if (B[i] <= dp.back().first) {
                dp = cut(dp, B[i]);
            } else {
                // Otherwise, append the current element to dp
                dp.push_back({B[i], 0});
            }

            bool is_added = false;

            // Iterate backwards through dp to check conditions
            for (int j = dp.size() - 1; j > 0; j--) {
                // If the second value of the current tuple is less than K-1
                if (dp[j].second < K - 1) {
                    // Cut dp and increment the second value of the current tuple
                    dp = cut(dp, dp[j].first - 1) + vector<pair<int, int>>({{dp[j].first, dp[j].second + 1}});

                    // If the last element in dp is less than B[i], append B[i] to dp
                    if (dp.back().first < B[i]) {
                        dp.push_back({B[i], 0});
                    }

                    is_added = true;
                    break;
                }
            }

            // If no element was added, return False
            if (!is_added) {
                return false;
            }
        }

        // If all conditions are satisfied, return True
        return true;
    };

    // Function to perform binary search to find the maximum K
    auto bis = [&](int x, int y) {
        // If the range is narrowed down to one element, return y
        if (y == x + 1) {
            return y;
        }

        // If is_possible is true for the midpoint, search in the left half
        if (is_possible((x + y) / 2)) {
            return bis(x, (x + y) / 2);
        }

        // Otherwise, search in the right half
        return bis((x + y) / 2, y);
    };

    // Print the result of the binary search
    cout << bis(0, N) << endl;

    return 0;
}

