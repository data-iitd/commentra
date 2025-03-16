

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to cut a list of tuples based on a given index
vector<pair<int, int>> cut(vector<pair<int, int>> array, int index) {
    if (index < 1) {
        return {};
    }
    if (index <= array[0].first) {
        return {{index, array[0].second}};
    }
    for (int i = array.size() - 1; i > 0; i--) {
        if (array[i - 1].first < index) {
            return vector<pair<int, int>>(array.begin(), array.begin() + i) + {{index, array[i].second}};
        }
    }
}

// Function to check if a given value of K is possible by modifying the list dp
bool is_possible(vector<pair<int, int>> &dp, int K, int a) {
    if (a <= dp.back().first) {
        dp = cut(dp, a);
    } else {
        dp.push_back({a, 0});
    }
    bool is_added = false;
    for (int i = dp.size() - 1; i >= 0; i--) {
        if (dp[i].second < K - 1) {
            dp = cut(dp, dp[i].first - 1) + {{dp[i].first, dp[i].second + 1}};
            if (dp.back().first < a) {
                dp.push_back({a, 0});
            }
            is_added = true;
            break;
        }
    }
    return is_added;
}

// Function to perform a binary search to find the maximum possible value of K
int bis(int x, int y) {
    if (y == x + 1) {
        return y;
    }
    vector<pair<int, int>> dp = {{A[0], 0}};
    if (is_possible(dp, (x + y) / 2, A[0])) {
        return bis(x, (x + y) / 2);
    } else {
        return bis((x + y) / 2, y);
    }
}

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    A = {A[0]} + vector<int>(A.begin() + 1, A.end());
    for (int i = 1; i < A.size(); i++) {
        if (A[i] <= A[i - 1]) {
            A[i] = A[i - 1] + 1;
        }
    }
    cout << bis(0, N) << endl;
    return 0;
}

