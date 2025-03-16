
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    const int64_t inf = numeric_limits<int64_t>::max();
    vector<int64_t> dist(N, inf);
    dist[0] = 0;

    vector<int> a(M), b(M), c(M);
    for (int i = 0; i < M; i++) {
        cin >> a[i] >> b[i] >> c[i];
        c[i] = -c[i];
    }

    for (int loop = 0; loop < N; loop++) {
        for (int i = 0; i < M; i++) {
            if (dist[a[i] - 1] == inf) {
                continue;
            }
            if (dist[b[i] - 1] > dist[a[i] - 1] + c[i]) {
                dist[b[i] - 1] = dist[a[i] - 1] + c[i];
            }
        }
    }

    int64_t ans = dist[N - 1];
    vector<bool> navigate(N);
    for (int loop = 0; loop < N; loop++) {
        for (int i = 0; i < M; i++) {
            if (dist[a[i] - 1] == inf) {
                continue;
            }
            if (dist[b[i] - 1] > dist[a[i] - 1] + c[i]) {
                dist[b[i] - 1] = dist[a[i] - 1] + c[i];
                navigate[b[i] - 1] = true;
            }
            if (navigate[a[i] - 1]) {
                navigate[b[i] - 1] = true;
            }
        }
    }

    if (navigate[N - 1]) {
        cout << "inf" << endl;
    } else {
        cout << -ans << endl;
    }

    return 0;
}
