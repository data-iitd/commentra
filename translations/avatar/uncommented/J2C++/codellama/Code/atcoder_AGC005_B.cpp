
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }
    vector<int> leftl(N);
    vector<int> rightl(N);
    queue<int> que;
    int index = 0;
    while (index < N) {
        while (!que.empty() && a[que.front()] > a[index]) {
            int ind = que.front();
            rightl[ind] = index - ind - 1;
            que.pop();
        }
        que.push(index++);
    }
    while (!que.empty()) {
        int ind = que.front();
        rightl[ind] = N - ind - 1;
        que.pop();
    }
    index = N - 1;
    while (index >= 0) {
        while (!que.empty() && a[que.front()] > a[index]) {
            int ind = que.front();
            leftl[ind] = ind - index - 1;
            que.pop();
        }
        que.push(index--);
    }
    while (!que.empty()) {
        int ind = que.front();
        leftl[ind] = ind - index - 1;
        que.pop();
    }
    long ans = 0;
    for (int i = 0; i < N; ++i) {
        ans += (long)a[i] * (leftl[i] + 1) * (rightl[i] + 1);
    }
    cout << ans << endl;
    return 0;
}

