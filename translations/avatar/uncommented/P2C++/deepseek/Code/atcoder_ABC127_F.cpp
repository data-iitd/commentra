#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

int main() {
    int q;
    std::cin >> q;
    std::vector<int> p1;
    std::vector<int> p2;
    std::priority_queue<int> pq2;
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq1;
    int sum_b = 0;
    int sum_p1 = 0;
    int sum_p2 = 0;

    for (int i = 0; i < q; ++i) {
        int query;
        std::cin >> query;
        if (query == 2) {
            if (pq1.size() == pq2.size()) {
                std::cout << -pq2.top() << " " << sum_p1 - pq1.size() * -pq2.top() + pq2.size() * -pq2.top() - sum_p2 + sum_b << "\n";
            } else {
                std::cout << pq1.top() << " " << sum_p1 - pq1.size() * pq1.top() + pq2.size() * pq1.top() - sum_p2 + sum_b << "\n";
            }
        } else {
            int x, a;
            std::cin >> x >> a;
            sum_b += a;
            if (pq1.empty()) {
                pq1.push(x);
                sum_p1 += x;
            } else if (pq1.top() <= x) {
                pq1.push(x);
                sum_p1 += x;
            } else {
                pq2.push(x);
                sum_p2 += x;
            }
            if (pq1.size() < pq2.size()) {
                int k = pq2.top();
                pq2.pop();
                pq1.push(k);
                sum_p2 -= k;
                sum_p1 += k;
            }
            if (pq1.size() - 1 > pq2.size()) {
                int k = pq1.top();
                pq1.pop();
                pq2.push(k);
                sum_p1 -= k;
                sum_p2 += k;
            }
        }
    }
    return 0;
}
