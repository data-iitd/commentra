#include <stdio.h>
#include <stdlib.h>
#include <deque>

int main() {
    int N;
    scanf("%d", &N);
    int a[N];
    for (int i = 0; i < N; ++i) {
        scanf("%d", &a[i]);
    }
    int leftl[N], rightl[N];
    std::deque<int> que;
    int index = 0;
    while (index < N) {
        while (!que.empty() && a[que.front()] > a[index]) {
            int ind = que.front();
            que.pop_front();
            rightl[ind] = index - ind - 1;
        }
        que.push_front(index++);
    }
    while (!que.empty()) {
        int ind = que.front();
        que.pop_front();
        rightl[ind] = N - ind - 1;
    }
    index = N - 1;
    while (index >= 0) {
        while (!que.empty() && a[que.front()] > a[index]) {
            int ind = que.front();
            que.pop_front();
            leftl[ind] = ind - index - 1;
        }
        que.push_front(index--);
    }
    while (!que.empty()) {
        int ind = que.front();
        que.pop_front();
        leftl[ind] = ind - index - 1;
    }
    long long ans = 0;
    for (int i = 0; i < N; ++i) {
        ans += (long long)a[i] * (leftl[i] + 1) * (rightl[i] + 1);
    }
    printf("%lld\n", ans);
    return 0;
}
