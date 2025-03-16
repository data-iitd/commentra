#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> a(N, 0);

    for (int i = 0; i < M; ++i) {
        int k;
        cin >> k;
        for (int j = 0; j < k; ++j) {
            int s;
            cin >> s;
            --s;
            a[s] |= (1 << i);
        }
    }

    vector<int> p(M);
    int x = 0;

    for (int i = 0; i < M; ++i) {
        cin >> p[i];
        x |= (p[i] << i);
    }

    int ans = 0;

    for (int s = 0; s < (1 << N); ++s) {
        int t = 0;
        for (int i = 0; i < N; ++i) {
            if (s & (1 << i)) {
                t ^= a[i];
            }
        }
        if (x == t) {
            ++ans;
        }
    }

    cout << ans << endl;

    return 0;
}

