#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> S(N);
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
        cout << ans << endl;
    } else if (N - K != 0) {
        for (int i = 0; i <= N - K; i++) {
            int min_val = S[i];
            int max_val = S[i + K - 1];
            if (min_val < 0 && max_val > 0) {
                temp = min(2 * (-min_val) + max_val, (-min_val) + 2 * max_val);
            } else {
                temp = max(abs(min_val), abs(max_val));
            }
            ans = min(ans, temp);
        }
        cout << ans << endl;
    } else {
        int min_val = S[0];
        int max_val = S[N - 1];
        if (min_val < 0 && max_val > 0) {
            cout << min(2 * (-min_val) + max_val, (-min_val) + 2 * max_val) << endl;
        } else {
            cout << max(abs(min_val), abs(max_val)) << endl;
        }
    }

    return 0;
}

// <END-OF-CODE>
