
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    priority_queue<pair<int, int>> pq;
    for (int i = 0; i < n; i++) {
        int day, salary;
        cin >> day >> salary;
        pq.push({-day, -salary});
    }
    vector<int> ans;
    while (!pq.empty()) {
        int day = -pq.top().first;
        int salary = -pq.top().second;
        pq.pop();
        if (ans.size() < m) {
            ans.push_back(salary);
        } else if (ans.size() == m) {
            if (ans[0] < salary) {
                ans[0] = salary;
                pq.push({-day, -ans[0]});
            }
        }
    }
    int sum = 0;
    for (int i = 0; i < ans.size(); i++) {
        sum += ans[i];
    }
    cout << sum << endl;
    return 0;
}
