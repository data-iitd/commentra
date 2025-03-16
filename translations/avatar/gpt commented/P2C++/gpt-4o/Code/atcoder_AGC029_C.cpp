#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to cut the array based on a given index
vector<pair<int, int>> cut(vector<pair<int, int>>& array, int index) {
    // If the index is less than 1, return an empty vector
    if (index < 1) {
        return {};
    }
    
    // If the index is less than or equal to the first element, return it with the first element's second value
    if (index <= array[0].first) {
        return {{index, array[0].second}};
    }
    
    // Iterate backwards through the array to find the appropriate cut point
    for (int i = array.size() - 1; i > 0; --i) {
        if (array[i - 1].first < index) {
            vector<pair<int, int>> result(array.begin(), array.begin() + i);
            result.push_back({index, array[i].second});
            return result;
        }
    }
    return {};
}

// Function to check if a certain condition is possible with K
bool is_possible(int K, const vector<int>& A) {
    vector<pair<int, int>> dp = {{A[0], 0}};
    
    // Iterate through the remaining elements in A
    for (size_t i = 1; i < A.size(); ++i) {
        int a = A[i];
        
        // If the current element is less than or equal to the last element in dp, cut dp
        if (a <= dp.back().first) {
            dp = cut(dp, a);
        } else {
            // Otherwise, append the current element to dp
            dp.push_back({a, 0});
        }
        
        bool is_added = false;
        
        // Iterate backwards through dp to check conditions
        for (int j = dp.size() - 1; j >= 0; --j) {
            // If the second value of the current tuple is less than K-1
            if (dp[j].second < K - 1) {
                dp = cut(dp, dp[j].first - 1);
                dp.push_back({dp[j].first, dp[j].second + 1});
                
                // If the last element in dp is less than a, append a to dp
                if (dp.back().first < a) {
                    dp.push_back({a, 0});
                }
                
                is_added = true;
                break;
            }
        }
        
        // If no element was added, return false
        if (!is_added) {
            return false;
        }
    }
    
    // If all conditions are satisfied, return true
    return true;
}

// Function to perform binary search to find the maximum K
int bis(int x, int y, const vector<int>& A) {
    // If the range is narrowed down to one element, return y
    if (y == x + 1) {
        return y;
    }
    // If is_possible is true for the midpoint, search in the left half
    else if (is_possible((x + y) / 2, A)) {
        return bis(x, (x + y) / 2, A);
    }
    // Otherwise, search in the right half
    else {
        return bis((x + y) / 2, y, A);
    }
}

int main() {
    // Read input from the user
    string line;
    getline(cin, line); // To consume the first input line
    getline(cin, line); // To read the second input line

    // Parse the input into a vector of integers
    vector<int> A;
    int num;
    istringstream iss(line);
    while (iss >> num) {
        A.push_back(num);
    }

    // Filter the list to keep only non-increasing elements
    vector<int> filteredA;
    filteredA.push_back(A[0]);
    for (size_t i = 1; i < A.size(); ++i) {
        if (A[i - 1] >= A[i]) {
            filteredA.push_back(A[i]);
        }
    }

    // Get the length of the filtered list
    int N = filteredA.size();

    // Print the result of the binary search
    cout << bis(0, N, filteredA) << endl;

    return 0;
}

// <END-OF-CODE>
