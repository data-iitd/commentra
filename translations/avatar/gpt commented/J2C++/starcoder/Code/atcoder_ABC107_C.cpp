#include <bits/stdc++.h>

using namespace std;

int main() {
    // Create a Scanner object to read input from the console
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin.exceptions(ios::badbit);
    int N, K;
    cin >> N >> K;
    int S[N];
    for (int i = 0; i < N; i++) {
        cin >> S[i];
    }
    int temp = 0;
    int ans = 1000000000;
    if (K == 1) {
        for (int i = 0; i < N; i++) {
            temp = S[i];
            ans = min(abs(temp), ans);
        }
        cout << ans << "\n";
    } else if (N - K!= 0) {
        for (int i = 0; i <= N - K; i++) {
            int min = S[i];
            int max = S[i + K - 1];
            if (min < 0 && max > 0) {
                temp = min(2 * (-min) + max, (-min) + 2 * max);
            } else {
                temp = max(abs(min), abs(max));
            }
            ans = min(ans, temp);
        }
        cout << ans << "\n";
    } else {
        int min = S[0];
        int max = S[N - 1];
        if (min < 0 && max > 0) {
            cout << min(2 * (-min) + max, (-min) + 2 * max) << "\n";
        } else {
            cout << max(abs(min), abs(max)) << "\n";
        }
    }
    return 0;
}

