#include <iostream>
#include <vector>

using namespace std;

// Defining a helper function to find the index of the last occurrence of an element
// in a list, and the index and value of the previous occurrence
vector<pair<int, int>> cut(vector<pair<int, int>> array, int index) {
    // Base case: if index is less than 1, return an empty list
    if (index < 1) {
        return vector<pair<int, int>>();
    }

    // Base case: if index is less than or equal to the first element in the array
    if (index <= array[0].first) {
        return vector<pair<int, int>>({index, array[0].second});
    }

    // Iterating through the array from the end to the beginning
    for (int i = array.size() - 1; i > 0; i--) {
        // If the previous element is smaller than the index, return the sublist up to that index
        if (array[i - 1].first < index) {
            return vector<pair<int, int>>(array.begin(), array.begin() + i) + vector<pair<int, int>>({index, array[i].second});
        }
    }
}

// Defining a helper function to check if it's possible to add a certain number of elements
// to the list while maintaining the condition that the previous element is smaller than the current one
bool is_possible(int K, vector<pair<int, int>> dp) {
    // Initializing an empty list to store the indices and values of the elements in the list
    vector<pair<int, int>> dp_ = {dp[0]};

    // Iterating through the list starting from the second element
    for (int i = 1; i < dp.size(); i++) {
        // If the current element is smaller than the last element in the dp list,
        // we need to cut the list at the previous index and add the current element
        if (dp[i].first <= dp_[0].first) {
            dp_ = cut(dp_, dp[i].first);
        }

        // Adding the current element to the dp list
        dp_.push_back(dp[i]);

        // Initializing a flag to check if we need to add an element to the dp list
        bool is_added = false;

        // Iterating through the dp list from the end to the beginning
        for (int j = dp_.size() - 1; j > 0; j--) {
            // If the previous element has a smaller value and enough space to add the current element,
            // we need to cut the list at the previous index and add the current element
            if (dp_[j].second < K - 1) {
                dp_ = cut(dp_, dp_[j].first - 1) + vector<pair<int, int>>({dp_[j].first, dp_[j].second + 1});

                // Checking if the last element in the dp list is smaller than the current element
                if (dp_.back().first < dp[i].first) {
                    dp_.push_back(dp[i]);
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

// Defining a helper function to find the binary index of a number in the list
int bis(int x, int y, vector<int> A) {
    // Base case: if y is one more than x, return y
    if (y == x + 1) {
        return y;
    }

    // Recursively finding the binary index of x and y using the is_possible function
    if (is_possible((x + y) / 2, vector<pair<int, int>>(A.begin() + x, A.begin() + y))) {
        return bis(x, (x + y) / 2, A);
    }

    // If is_possible returns False for (x + y) / 2 and y, return the binary index of y
    else {
        return bis((x + y) / 2, y, A);
    }
}

int main() {
    // Taking input from user and converting it into a list of integers
    string input;
    cin >> input;
    vector<int> A;
    for (int i = 0; i < input.size(); i++) {
        if (input[i] != ' ') {
            A.push_back(input[i] - '0');
        }
    }

    // Adding the first element of the list to the beginning of the list
    // to make the first index 0 based instead of 1 based
    A = vector<int>({A[0]}) + A;

    // Assigning the length of the list to a variable for easier reference
    int N = A.size();

    // Printing the result of the binary index function
    cout << bis(0, N, A) << endl;

    return 0;
}

