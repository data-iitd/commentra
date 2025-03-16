
#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int N, K, S[100000], temp, ans = 1000000000;
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> S[i];
    }
    if (K == 1) {
        for (int i = 0; i < N; i++) {
            temp = S[i];
            ans = min(abs(temp), ans);
        }
        cout << ans << endl;
    } else if (N - K != 0) {
        int min, max;
        for (int i = 0; i <= N - K; i++) {
            min = S[i];
            max = S[i + K - 1];
            if (min < 0 && max > 0) {
                temp = 2 * (abs(min)) + max;
            } else {
                temp = max(abs(min), abs(max));
            }
            ans = min(ans, temp);
        }
        cout << ans << endl;
    } else {
        min = S[0];
        max = S[N - 1];
        if (min < 0 && max > 0) {
            cout << min(2 * (abs(min)) + max, (abs(min)) + 2 * max) << endl;
        } else {
            cout << max(abs(min), abs(max)) << endl;
        }
    }
    return 0;
}

