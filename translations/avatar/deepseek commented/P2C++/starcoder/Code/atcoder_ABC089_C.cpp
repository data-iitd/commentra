#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    vector<string> S(N);
    for (int i = 0; i < N; i++) {
        cin >> S[i];
    }

    vector<int> march_lis(5, 0);
    for (int i = 0; i < N; i++) {
        if (S[i][0] == 'M' || S[i][0] == 'A' || S[i][0] == 'R' || S[i][0] == 'C' || S[i][0] == 'H') {
            march_lis[S[i][0] - 'M']++;
        }
    }

    int ans = 0;
    for (int x = 0; x < 5; x++) {
        for (int y = 0; y < 5; y++) {
            for (int z = 0; z < 5; z++) {
                if (x + y + z == 3) {
                    ans += march_lis[x] * march_lis[y] * march_lis[z];
                }
            }
        }
    }

    cout << ans << "\n";

    return 0;
}

