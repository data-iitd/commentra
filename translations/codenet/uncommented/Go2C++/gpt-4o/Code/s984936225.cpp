#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    long long Inf = 1LL << 62; // Use long long to handle large values
    vector<int> a(M), b(M), c(M);
    
    for (int i = 0; i < M; i++) {
        cin >> a[i] >> b[i] >> c[i];
        c[i] = -c[i]; // Negate the cost
    }

    vector<long long> dist(N, Inf); // Initialize distances with Inf
    dist[0] = 0; // Starting point

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

    long long ans = dist[N - 1]; // Minimum distance to the last node
    vector<bool> navigate(N, false);
    
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

// <END-OF-CODE>
