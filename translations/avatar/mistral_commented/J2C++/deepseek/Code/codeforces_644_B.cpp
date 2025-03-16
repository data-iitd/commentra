#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    int n, b;
    cin >> n >> b;
    vector<long long> ans(n);
    queue<long long> q;

    for (int i = 0; i < n; ++i) {
        int t, d;
        cin >> t >> d;

        while (!q.empty() && q.front() <= t) {
            q.pop();
        }

        if (q.size() <= b) {
            ans[i] = (q.empty() ? t : q.back()) + d;
            q.push(ans[i]);
        } else {
            ans[i] = -1;
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << ans[i] << " ";
    }

    return 0;
}

