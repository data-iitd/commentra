#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

// The abs function returns the absolute value of an integer n.
int abs(int n) {
    return n < 0 ? -n : n;
}

// The solve function reads an integer n and a vector of integers as.
// It then creates a new vector xs where each element is calculated as a - i + 1.
// The vector xs is sorted.
// The median of the sorted xs is chosen as b.
// The function calculates the sum of absolute differences between each element in xs and b.
// The result is printed.
void solve() {
    int n;
    cin >> n;
    vector<int> as(n);
    for (int i = 0; i < n; ++i) {
        cin >> as[i];
    }

    vector<int> xs(n);
    for (int i = 0; i < n; ++i) {
        xs[i] = as[i] - i + 1;
    }
    sort(xs.begin(), xs.end()); // Sort the vector xs

    int b = xs[n / 2]; // Choose the median as b
    int ans = 0;
    for (int x : xs) {
        ans += abs(x - b);
    }
    cout << ans << endl;
}

int main() {
    solve();
    return 0;
}

