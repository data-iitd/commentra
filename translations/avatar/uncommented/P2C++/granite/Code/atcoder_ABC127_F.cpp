
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    int q;
    cin >> q;
    vector<int> ans(2, 0);
    priority_queue<int> p1, p2;
    long long sum_b = 0, sum_p1 = 0, sum_p2 = 0;
    for (int i = 0; i < q; i++) {
        int query;
        cin >> query;
        if (query == 1) {
            int a, b;
            cin >> a >> b;
            sum_b += b;
            if (p1.empty()) {
                p1.push(a);
                sum_p1 += a;
            } else if (p1.top() <= a) {
                p1.push(a);
                sum_p1 += a;
            } else {
                p2.push(-a);
                sum_p2 -= a;
            }
            if (p1.size() < p2.size()) {
                int tmp = p2.top();
                p2.pop();
                p1.push(-tmp);
                sum_p2 += tmp;
                sum_p1 -= tmp;
            }
            if (p1.size() - 1 > p2.size()) {
                int tmp = p1.top();
                p1.pop();
                p2.push(-tmp);
                sum_p1 -= tmp;
                sum_p2 += tmp;
            }
        } else {
            if (p1.size() == p2.size()) {
                ans[0] = p2.top();
                ans[1] = sum_p1 - p1.size() * p2.top() + p2.size() * p2.top() - sum_p2 + sum_b;
            } else {
                ans[0] = p1.top();
                ans[1] = sum_p1 - p1.size() * p1.top() + p2.size() * p1.top() - sum_p2 + sum_b;
            }
            cout << ans[0] << " " << ans[1] << endl;
        }
    }
    return 0;
}
