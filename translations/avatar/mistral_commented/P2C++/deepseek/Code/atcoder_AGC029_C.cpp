#include <iostream>
#include <vector>
#include <utility>

using namespace std;

// Helper function to find the index of the last occurrence of an element
// in a list, and the index and value of the previous occurrence
vector<pair<int, int>> cut(const vector<pair<int, int>>& array, int index) {
    // Base case: if index is less than 1, return an empty list
    if (index < 1) {
        return {};
    }

    // Base case: if index is less than or equal to the first element in the array
    if (index <= array[0].first) {
        return {{index, array[0].second}};
    }

    // Iterating through the array from the end to the beginning
    for (int i = array.size() - 1; i > 0; --i) {
        // If the previous element is smaller than the index, return the sublist up to that index
        if (array[i - 1].first < index) {
            vector<pair<int, int>> result(array.begin(), array.begin() + i);
            result.push_back({index, array[i].second});
            return result;
        }
    }
    return {};
}

// Helper function to check if it's possible to add a certain number of elements
// to the list while maintaining the condition that the previous element is smaller than the current one
bool is_possible(int K, const vector<int>& A) {
    // Initializing an empty list to store the indices and values of the elements in the list
    vector<pair<int, int>> dp = {{A[0], 0}};

    // Iterating through the list starting from the second element
    for (int a : A) {
        // If the current element is smaller than the last element in the dp list,
        // we need to cut the list at the previous index and add the current element
        if (a <= dp.back().first) {
            dp = cut(dp, a);
        }

        // Adding the current element to the dp list
        dp.push_back({a, 0});

        // Initializing a flag to check if we need to add an element to the dp list
        bool is_added = false;

        // Iterating through the dp list from the end to the beginning
        for (int j = dp.size() - 1; j >= 0; --j) {
            // If the previous element has a smaller value and enough space to add the current element,
            // we need to cut the list at the previous index and add the current element
            if (dp[j].second < K - 1) {
                dp = cut(dp, dp[j].first - 1);
                dp.push_back({dp[j].first, dp[j].second + 1});

                // Checking if the last element in the dp list is smaller than the current element
                if (dp.back().first < a) {
                    dp.push_back({a, 0});
                    is_added = true;
                    break;
                }
            }
        }

        // If we didn't add an element to the dp list, the current number can't be added
        if (!is_added) {
            return false;
        }
    }
    return true;
}

// Helper function to find the binary index of a number in the list
int bis(int x, int y, const vector<int>& A) {
    // Base case: if y is one more than x, return y
    if (y == x + 1) {
        return y;
    }

    // Recursively finding the binary index of x and y using the is_possible function
    if (is_possible((x + y) / 2, A)) {
        return bis(x, (x + y) / 2, A);
    } else {
        return bis((x + y) / 2, y, A);
    }
}

int main() {
    // Taking input from user and converting it into a list of integers
    string input_;
    getline(cin, input_);
    vector<int> A;
    string temp;
    for (char c : input_) {
        if (c == ' ') {
            A.push_back(stoi(temp));
            temp.clear();
        } else {
            temp += c;
        }
    }
    if (!temp.empty()) {
        A.push_back(stoi(temp));
    }

    // Adding the first element of the list to the beginning of the list
    // to make the first index 0 based instead of 1 based
    A = {A[0]} + vector<int>(A.begin() + 1, A.end());

    // Assigning the length of the list to a variable for easier reference
    int N = A.size();

    // Printing the result of the binary index function
    cout << bis(0, N, A) << endl;

    return 0;
}
