
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Helper function to find the index of the last occurrence of an element in a vector
// and the index and value of the previous occurrence
vector<pair<int, int>> cut(vector<pair<int, int>>& array, int index) {
    // Base case: if index is less than 1, return an empty vector
    if (index < 1) {
        return {};
    }

    // Base case: if index is less than or equal to the first element in the array
    if (index <= array[0].first) {
        return {{index, array[0].second}};
    }

    // Iterating through the array from the end to the beginning
    for (int i = array.size() - 1; i > 0; i--) {
        // If the previous element is smaller than the index, return the subvector up to that index
        if (array[i - 1].first < index) {
            return vector<pair<int, int>>(array.begin(), array.begin() + i) + {{index, array[i].second}};
        }
    }
}

// Helper function to check if it's possible to add a certain number of elements
// to the vector while maintaining the condition that the previous element is smaller than the current one
bool is_possible(int K, vector<pair<int, int>>& dp) {
    // Initializing an empty vector to store the indices and values of the elements in the vector
    dp = {{A[0], 0}};

    // Iterating through the vector starting from the second element
    for (int i = 1; i < A.size(); i++) {
        // If the current element is smaller than the last element in the dp vector,
        // we need to cut the vector at the previous index and add the current element
        if (A[i] <= dp.back().first) {
            dp = cut(dp, A[i]);
        }

        // Adding the current element to the dp vector
        dp.push_back({A[i], 0});

        // Initializing a flag to check if we need to add an element to the dp vector
        bool is_added = false;

        // Iterating through the dp vector from the end to the beginning
        for (int j = dp.size() - 1; j >= 0; j--) {
            // If the previous element has a smaller value and enough space to add the current element,
            // we need to cut the vector at the previous index and add the current element
            if (dp[j].second < K - 1) {
                dp = cut(dp, dp[j].first - 1) + {{dp[j].first, dp[j].second + 1}};

                // Checking if the last element in the dp vector is smaller than the current element
                if (dp.back().first < A[i]) {
                    dp.push_back({A[i], 0});
                    is_added = true;
                    break;
                }
            }
        }

        // If we didn't add an element to the dp vector, the current number can't be added
        if (!is_added) {
            return false;
        }
    }

    return true;
}

// Helper function to find the binary index of a number in the vector
int bis(int x, int y) {
    // Base case: if y is one more than x, return y
    if (y == x + 1) {
        return y;
    }

    // Recursively finding the binary index of x and y using the is_possible function
    if (is_possible((x + y) / 2, dp)) {
        return bis(x, (x + y) / 2);
    } else {
        return bis((x + y) / 2, y);
    }
}

int main() {
    // Taking input from user and converting it into a vector of integers
    string input;
    getline(cin, input);
    vector<int> A;
    stringstream ss(input);
    int num;
    while (ss >> num) {
        A.push_back(num);
    }

    // Adding the first element of the vector to the beginning of the vector
    // to make the first index 0 based instead of 1 based
    A.insert(A.begin(), A[0]);

    // Assigning the size of the vector to a variable for easier reference
    int N = A.size();

    // Initializing a vector to store the indices and values of the elements in the vector
    vector<pair<int, int>> dp;

    // Printing the result of the binary index function
    cout << bis(0, N) << endl;

    return 0;
}

