
#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define MAX INT_MAX
#define LMAX LLONG_MAX

int main() {
    int N, A[100000];
    long long K;
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        A[i]--;
    }
    set<int> used;
    int idx[100000], pos[100000];
    int next = 0, cur = 0;
    while (!used.count(next)) {
        used.insert(next);
        idx[next] = cur;
        pos[cur] = next;
        next = A[next];
        cur++;
    }
    long long a = cur - idx[next];
    long long b = idx[next];
    int ans = (int)((10000 * a + K - b) % a + b);
    if (b > K) ans = (int)K;
    cout << pos[ans] + 1 << endl;
    return 0;
}
//END-OF-CODE