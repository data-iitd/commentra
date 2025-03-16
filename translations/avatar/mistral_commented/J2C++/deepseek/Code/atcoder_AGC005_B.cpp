#include <iostream>
#include <deque>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> a(N);

    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }

    vector<int> leftl(N, 0);
    vector<int> rightl(N, 0);
    deque<int> que;
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
        ans += (long long) a[i] * (leftl[i] + 1) * (rightl[i] + 1);
    }

    cout << ans << endl;

    return 0;
}

