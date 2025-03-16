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
            s--;
            a[s] |= (1 << i);
        }
    }

    bitset<10> p;
    for (int i = 0; i < M; ++i) {
        int x;
        cin >> x;
        p[i] = x;
    }

    int ans = 0;
    for (int s = 0; s < (1 << N); ++s) {
        bitset<10> t;
        for (int i = 0; i < N; ++i) {
            if (s & (1 << i)) {
                t ^= a[i];
            }
        }
        if (p == t) {
            ++ans;
        }
    }

    cout << ans << endl;

    return 0;
}

