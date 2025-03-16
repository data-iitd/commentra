
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to cut the array based on a given index
vector<pair<int, int>> cut(vector<pair<int, int>> array, int index) {
    // If the index is less than 1, return an empty list
    if (index < 1) {
        return {};
    }
    
    // If the index is less than or equal to the first element, return it with the first element's second value
    if (index <= array[0].first) {
        return {{index, array[0].second}};
    }
    
    // Iterate backwards through the array to find the appropriate cut point
    for (int i = array.size() - 1; i > 0; i--) {
        if (array[i - 1].first < index) {
            return vector<pair<int, int>>(array.begin(), array.begin() + i) + {{index, array[i].second}};
        }
    }
}

// Function to check if a certain condition is possible with K
bool is_possible(int K, vector<pair<int, int>> array) {
    // Initialize the dynamic programming array with the first element
    vector<pair<int, int>> dp = {{array[0].first, 0}};
    
    // Iterate through the remaining elements in A
    for (int i = 1; i < array.size(); i++) {
        // If the current element is less than or equal to the last element in dp, cut dp
        if (array[i].first <= dp.back().first) {
            dp = cut(dp, array[i].first);
        } else {
            // Otherwise, append the current element to dp
            dp.push_back({array[i].first, 0});
        }
        
        bool is_added = false;
        
        // Iterate backwards through dp to check conditions
        for (int j = dp.size() - 1; j >= 0; j--) {
            // If the second value of the current tuple is less than K-1
            if (dp[j].second < K - 1) {
                // Cut dp and increment the second value of the current tuple
                dp = cut(dp, dp[j].first - 1) + {{dp[j].first, dp[j].second + 1}};
                
                // If the last element in dp is less than a, append a to dp
                if (dp.back().first < array[i].first) {
                    dp.push_back({array[i].first, 0});
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
int bis(int x, int y) {
    // If the range is narrowed down to one element, return y
    if (y == x + 1) {
        return y;
    }
    // If is_possible is true for the midpoint, search in the left half
    else if (is_possible((x + y) / 2, array)) {
        return bis(x, (x + y) / 2);
    }
    // Otherwise, search in the right half
    else {
        return bis((x + y) / 2, y);
    }
}

int main() {
    int n;
    cin >> n;
    
    // Parse the input into a vector of pairs
    vector<pair<int, int>> array;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (array.empty() || a > array.back().first) {
            array.push_back({a, 0});
        }
    }
    
    // Filter the vector to keep only non-increasing elements
    array = {array[0]};
    for (int i = 1; i < array.size(); i++) {
        if (array[i].first >= array[i - 1].first) {
            array[i].second = array[i - 1].second + 1;
        }
    }
    
    // Get the length of the filtered vector
    int N = array.size();
    
    // Print the result of the binary search
    cout << bis(0, N) << endl;
    
    return 0;
}

