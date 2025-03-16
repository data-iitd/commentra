#include <stdio.h>
#include <stdlib.h>
#include <deque>

int main() {
    int n, b;
    scanf("%d %d", &n, &b);
    long long ans[n];
    std::deque<long long> q;

    for (int i = 0; i < n; i++) {
        int t, d;
        scanf("%d %d", &t, &d);
        while (!q.empty() && q.front() <= t) {
            q.pop_front();
        }
        if (q.size() <= b) {
            ans[i] = (q.empty() ? t : q.back()) + d;
            q.push_back(ans[i]);
        } else {
            ans[i] = -1;
        }
    }

    for (int i = 0; i < n; ++i) {
        printf("%lld ", ans[i]);
    }

    return 0;
}
