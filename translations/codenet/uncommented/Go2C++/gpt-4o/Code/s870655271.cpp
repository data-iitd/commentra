#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int main() {
    int N, M;
    int ans = 0;
    cin >> N >> M;

    if (N == 1 && M == 1) {
        ans += 1;
    } else if (N > 1 && M > 1) {
        ans += (N - 2) * (M - 2);
    } else {
        ans += (N * M) - 2;
    }

    cout << ans << endl;

    return 0;
}

/* ---------------------------------------- */

int max(int x, int y) {
    return std::max(x, y);
}

int min(int x, int y) {
    return std::min(x, y);
}

int pow(int x, int y) {
    return static_cast<int>(std::pow(x, y));
}

int abs(int x) {
    return std::abs(x);
}

int floor(int x) {
    return static_cast<int>(std::floor(x));
}

struct SortBy {
    vector<int> arr;

    bool operator()(int i, int j) {
        return abs(i) < abs(j);
    }
};

// Note: The SortBy struct is not used in the main function, but it can be used with std::sort if needed.

