#include <iostream>
#include <vector>
#include <climits>

int main() {
    int N, M;
    std::cin >> N >> M;

    const long long Inf = 1LL << 62;
    std::vector<int> a(M), b(M), c(M);

    for (int i = 0; i < M; ++i) {
        std::cin >> a[i] >> b[i] >> c[i];
        c[i] = -c[i];
    }

    std::vector<long long> dist(N, Inf);
    dist[0] = 0;

    for (int loop = 0; loop < N; ++loop) {
        for (int i = 0; i < M; ++i) {
            if (dist[a[i] - 1] == Inf) continue;
            if (dist[b[i] - 1] > dist[a[i] - 1] + c[i]) {
                dist[b[i] - 1] = dist[a[i] - 1] + c[i];
            }
        }
    }

    std::vector<bool> navigate(N, false);

    for (int loop = 0; loop < N; ++loop) {
        for (int i = 0; i < M; ++i) {
            if (dist[a[i] - 1] == Inf) continue;
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
        std::cout << "inf" << std::endl;
    } else {
        std::cout << -dist[N - 1] << std::endl;
    }

    return 0;
}
