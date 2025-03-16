#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    int q;
    cin >> q;
    vector<int> ans = {0, 0};
    priority_queue<int> p1;
    priority_queue<int, vector<int>, greater<int>> p2;
    int sum_b = 0;
    int sum_p1 = 0;
    int sum_p2 = 0;

    for (int i = 0; i < q; ++i) {
        int query;
        cin >> query;
        if (query == 2) {
            if (p1.size() == p2.size()) {
                cout << -p2.top() << " " << sum_p1 - p1.size() * -p2.top() + p2.size() * -p2.top() - sum_p2 + sum_b << endl;
            } else {
                cout << p1.top() << " " << sum_p1 - p1.size() * p1.top() + p2.size() * p1.top() - sum_p2 + sum_b << endl;
            }
        } else {
            int x, y;
            cin >> x >> y;
            sum_b += y;
            if (p1.empty()) {
                p1.push(x);
                sum_p1 += x;
            } else if (p1.top() <= x) {
                p1.push(x);
                sum_p1 += x;
            } else {
                p2.push(x);
                sum_p2 += x;
                sum_p1 -= x;
            }
            if (p1.size() < p2.size()) {
                int k = p2.top();
                p2.pop();
                p1.push(k);
                sum_p2 -= k;
                sum_p1 += k;
            }
            if (p1.size() - 1 > p2.size()) {
                int k = p1.top();
                p1.pop();
                p2.push(k);
                sum_p1 -= k;
                sum_p2 += k;
            }
        }
    }
