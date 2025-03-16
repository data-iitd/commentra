#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    cin >> N >> K;
    string S;
    cin >> S;

    int seg_cnt = 0;
    for (int i = 0; i < N - 1; i++) {
        if (S[i]!= S[i + 1]) {
            seg_cnt++;
        }
    }

    int cur_happy = N - 1 - seg_cnt;

    if (2 * K >= seg_cnt) {
        cout << N - 1;
    } else {
        cout << cur_happy + 2 * K;
    }

    return 0;
}

