#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to cut a list of tuples based on a given index
vector<pair<int, int>> cut(const vector<pair<int, int>>& array, int index) {
    if (index < 1) {
        return {};
    }
    if (index <= array[0].first) {
        return {{index, array[0].second}};
    }
    for (int i = array.size() - 1; i > 0; --i) {
        if (array[i - 1].first < index) {
            vector<pair<int, int>> result(array.begin(), array.begin() + i);
            result.push_back({index, array[i].second});
            return result;
        }
    }
    return {};
}

// Function to check if a given value of K is possible by modifying the list dp
bool is_possible(int K, const vector<int>& A) {
    vector<pair<int, int>> dp = {{A[0], 0}};
    for (size_t i = 1; i < A.size(); ++i) {
        int a = A[i];
        if (a <= dp.back().first) {
            dp = cut(dp, a);
        } else {
            dp.push_back({a, 0});
        }
        bool is_added = false;
        for (int j = dp.size() - 1; j >= 0; --j) {
            if (dp[j].second < K - 1) {
                dp = cut(dp, dp[j].first - 1);
                dp.push_back({dp[j].first, dp[j].second + 1});
                if (dp.back().first < a) {
                    dp.push_back({a, 0});
                }
                is_added = true;
                break;
            }
        }
        if (!is_added) {
            return false;
        }
    }
    return true;
}

// Function to perform a binary search to find the maximum possible value of K
int bis(int x, int y, const vector<int>& A) {
    if (y == x + 1) {
        return y;
    } else if (is_possible((x + y) / 2, A)) {
        return bis(x, (x + y) / 2, A);
    } else {
        return bis((x + y) / 2, y, A);
    }
}

int main() {
    // Taking input from the user and processing it to create a list of integers
    int n;
    cin >> n; // Read the size of the array
    vector<int> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i]; // Read the elements of the array
    }

    // Modifying the list A to include only elements where the previous element is greater than or equal to the current element
    vector<int> modified_A = {A[0]};
    for (int i = 1; i < n; ++i) {
        if (A[i - 1] >= A[i]) {
            modified_A.push_back(A[i]);
        }
    }

    // Storing the length of the modified list A in N
    int N = modified_A.size();

    // Printing the result of the binary search
    cout << bis(0, N, modified_A) << endl;

    return 0;
}

// <END-OF-CODE>
