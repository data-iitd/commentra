#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to cut the array based on the index
vector<pair<int, int>> cut(vector<pair<int, int>>& array, int index) {
    if (index < 1) {
        return {};
    }
    if (index <= array[0].first) {
        return {{index, array[0].second}};
    }
    for (int i = array.size() - 1; i > 0; --i) {
        if (array[i - 1].first < index) {
            array.push_back({index, array[i].second});
            return vector<pair<int, int>>(array.begin(), array.begin() + i + 1);
        }
    }
    return {};
}

// Function to check if it's possible to add a certain number of elements
bool is_possible(int K, vector<int>& A) {
    vector<pair<int, int>> dp = {{A[0], 0}};
    for (int a : A) {
        if (a <= dp.back().first) {
            dp = cut(dp, a);
        }
        dp.push_back({a, 0});
        bool is_added = false;

        for (int j = dp.size() - 1; j >= 0; --j) {
            if (dp[j].second < K - 1) {
                dp = cut(dp, dp[j].first - 1);
                dp.push_back({dp[j].first, dp[j].second + 1});
                if (dp.back().first < a) {
                    dp.push_back({a, 0});
                    is_added = true;
                    break;
                }
            }
        }
        if (!is_added) {
            return false;
        }
    }
    return true;
}

// Function to find the binary index of a number in the list
int bis(int x, int y, vector<int>& A) {
    if (y == x + 1) {
        return y;
    }
    if (is_possible((x + y) / 2, A)) {
        return bis(x, (x + y) / 2, A);
    } else {
        return bis((x + y) / 2, y, A);
    }
}

int main() {
    // Taking input from user and converting it into a vector of integers
    string input;
    getline(cin, input);
    vector<int> A;
    int num;
    istringstream iss(input);
    while (iss >> num) {
        A.push_back(num);
    }

    // Adding the first element of the vector to the beginning of the vector
    A.insert(A.begin(), A[0]);
    A.erase(remove_if(A.begin() + 1, A.end(), [&](int j) { return A[0] < j; }), A.end());

    // Assigning the length of the vector to a variable for easier reference
    int N = A.size();

    // Printing the result of the binary index function
    cout << bis(0, N, A) << endl;

    return 0;
}

// <END-OF-CODE>
