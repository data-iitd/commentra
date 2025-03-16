#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    priority_queue<pair<int, int>> x; // max-heap for days and salaries
    priority_queue<int, vector<int>, greater<int>> y; // min-heap for salaries

    for (int i = 0; i < n; i++) {
        int day, salary;
        cin >> day >> salary;
        x.push(make_pair(-day, -salary)); // push negative values to simulate max-heap
    }

    while (!x.empty()) {
        auto [d, s] = x.top();
        x.pop();
        int r = m - y.size();
        if (r >= -d) {
            y.push(-s);
        } else {
            y.push(-s);
            y.pop();
        }
    }

    int total_salary = 0;
    while (!y.empty()) {
        total_salary += y.top();
        y.pop();
    }

    cout << total_salary << endl;
    return 0;
}

// <END-OF-CODE>
