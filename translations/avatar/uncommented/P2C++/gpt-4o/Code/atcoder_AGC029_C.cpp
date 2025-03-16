#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

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
    vector<int> A;
    int n, temp;
    cout << "Enter the number of elements: ";
    cin >> n;
    cout << "Enter the elements: ";
    for (int i = 0; i < n; ++i) {
        cin >> temp;
        A.push_back(temp);
    }

    // Remove non-increasing elements
    A = {A[0]};
    for (size_t i = 1; i < A.size(); ++i) {
        if (A[i] <= A[i - 1]) {
            A.push_back(A[i]);
        }
    }

    int N = A.size();
    cout << bis(0, N, A) << endl;

    return 0;
}

// <END-OF-CODE>
