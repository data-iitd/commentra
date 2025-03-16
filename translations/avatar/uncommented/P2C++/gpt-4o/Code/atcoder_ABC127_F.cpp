#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int q;
    cin >> q;
    vector<int> ans(2, 0);
    priority_queue<int, vector<int>, greater<int>> p1; // Min-heap for p1
    priority_queue<int> p2; // Max-heap for p2
    long long sum_b = 0;
    long long sum_p1 = 0;
    long long sum_p2 = 0;

    for (int i = 0; i < q; i++) {
        int type, value, b;
        cin >> type;

        if (type == 2) {
            if (p1.size() == p2.size()) {
                cout << -p2.top() << " " << sum_p1 - p1.size() * -p2.top() + p2.size() * -p2.top() - sum_p2 + sum_b << endl;
            } else {
                cout << p1.top() << " " << sum_p1 - p1.size() * p1.top() + p2.size() * p1.top() - sum_p2 + sum_b << endl;
            }
        } else {
            cin >> value >> b;
            sum_b += b;

            if (p1.empty()) {
                p1.push(value);
                sum_p1 += value;
            } else if (p1.top() <= value) {
                p1.push(value);
                sum_p1 += value;
            } else {
                p2.push(value);
                sum_p2 += value;
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

    return 0;
}
// <END-OF-CODE>
