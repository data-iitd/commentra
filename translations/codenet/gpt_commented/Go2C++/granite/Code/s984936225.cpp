
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    int Inf = 1 << 62; // Using a large value for infinity, considering the maximum possible distance

    vector<int> a(M), b(M), c(M);
    for (int i = 0; i < M; i++) {
        cin >> a[i] >> b[i] >> c[i];
        c[i] = -c[i]; // Negate the weights for the algorithm (to handle maximization)
    }

    vector<int> dist(N, Inf);
    dist[0] = 0;

    for (int loop = 0; loop < N; loop++) {
        for (int i = 0; i < M; i++) {
            if (dist[a[i] - 1] == Inf) {
                continue;
            }
            if (dist[b[i] - 1] > dist[a[i] - 1] + c[i]) {
                dist[b[i] - 1] = dist[a[i] - 1] + c[i];
            }
        }
    }

    int ans = dist[N - 1];
    vector<bool> navigate(N);

    for (int loop = 0; loop < N; loop++) {
        for (int i = 0; i < M; i++) {
            if (dist[a[i] - 1] == Inf) {
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
