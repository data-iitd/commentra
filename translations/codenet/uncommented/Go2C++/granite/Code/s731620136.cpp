
// +build ignore
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    string S;
    cin >> N >> S;

    if (N == 0) {
        cout << 0 << endl;
        return 0;
    }

    if (N < 4) {
        cout << 0 << endl;
        return 0;
    }

    int nr = 0, nb = 0, ng = 0;
    for (char c : S) {
        if (c == 'R') nr++;
        if (c == 'B') nb++;
        if (c == 'G') ng++;
    }

    int same = 0;
    for (int a = 1; a < N; a++) {
        int i = 0, j = a, k = 2 * a;
        if (k >= N) break;
        while (k < N) {
            if (S[i]!= S[j] && S[i]!= S[k] && S[j]!= S[k]) {
                same++;
            }
            i++, j++, k++;
        }
    }

    int tot = nr * nb * ng;
    cout << tot - same << endl;

    return 0;
}

