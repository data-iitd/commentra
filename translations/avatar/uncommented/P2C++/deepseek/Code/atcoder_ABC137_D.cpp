#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    priority_queue<pair<int, int>> x;
    vector<int> y;

    for (int i = 0; i < n; ++i) {
        int day, salary;
        cin >> day >> salary;
        x.push({-day, -salary});
    }

    while (!x.empty()) {
        auto [d, s] = x.top();
        x.pop();
        int r = m - y.size();
        if (r >= -d) {
            y.push_back(-s);
        } else {
            if (!y.empty()) {
                y.push_back(-s);
                sort(y.begin(), y.end());
                y.pop_back();
            }
        }
    }

    int sum = 0;
    for (int salary : y) {
        sum += salary;
    }
    cout << sum << endl;

    return 0;
}
