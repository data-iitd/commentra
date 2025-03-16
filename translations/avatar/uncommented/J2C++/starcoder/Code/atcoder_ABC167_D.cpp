#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    long long K;
    cin >> N >> K;
    int A[N];
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    set<int> used;
    int idx[N], pos[N];
    int next = 0, cur = 0;
    while (!used.count(next)) {
        used.insert(next);
        idx[next] = cur;
        pos[cur] = next;
        next = A[next];
        cur++;
    }
    long a = (long)cur - idx[next];
    long b = (long)idx[next];
    int ans = (int)((10000 * a + K - b) % a + b);
    if (b > K) ans = (int)K;
    cout << pos[ans] + 1 << endl;
    return 0;
}

