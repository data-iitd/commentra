#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    long long MOD = 1e9 + 7;
    int N, K;
    cin >> N >> K;
    string S;
    cin >> S;

    int seg_cnt = 0;
    for (int i = 0; i < N - 1; i++) {
        if (S[i] != S[i + 1]) {
            seg_cnt++;
        }
    }

    int cur_happy = N - 1 - seg_cnt;
    int ans;
    if (2 * K >= seg_cnt) {
        ans = N - 1;
    } else {
        ans = cur_happy + 2 * K;
    }

    cout << ans << endl;

    return 0;
}

// <END-OF-CODE>
