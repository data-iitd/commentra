
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <assert.h>
#include <queue>
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    int q;
    scanf("%d", &q);
    long long ans[2] = {0, 0};
    priority_queue<long long> p1, p2;
    long long sum_b = 0;
    long long sum_p1 = 0;
    long long sum_p2 = 0;
    for (int i = 0; i < q; i++) {
        int t;
        scanf("%d", &t);
        if (t == 1) {
            long long a, b;
            scanf("%lld%lld", &a, &b);
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
                long long tmp = p2.top();
                p2.pop();
                p1.push(-tmp);
                sum_p2 += tmp;
                sum_p1 -= tmp;
            }
            if (p1.size() - 1 > p2.size()) {
                long long tmp = p1.top();
                p1.pop();
                p2.push(-tmp);
                sum_p1 -= tmp;
                sum_p2 += tmp;
            }
        } else {
            if (p1.size() == p2.size()) {
                printf("%lld %lld\n", -p2.top(), sum_p1 - p1.size() * -p2.top() + p2.size() * -p2.top() - sum_p2 + sum_b);
            } else {
                printf("%lld %lld\n", p1.top(), sum_p1 - p1.size() * p1.top() + p2.size() * p1.top() - sum_p2 + sum_b);
            }
        }
    }
    return 0;
}
