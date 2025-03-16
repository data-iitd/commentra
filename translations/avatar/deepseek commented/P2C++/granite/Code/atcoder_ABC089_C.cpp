
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<string> S(N);
    for (int i = 0; i < N; i++) {
        cin >> S[i];
    }
    vector<int> march_lis(5, 0);
    vector<char> march = {'M', 'A', 'R', 'C', 'H'};
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 5; j++) {
            if (S[i][0] == march[j]) {
                march_lis[j]++;
                break;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = i + 1; j < 4; j++) {
            for (int k = j + 1; k < 5; k++) {
                ans += march_lis[i] * march_lis[j] * march_lis[k];
            }
        }
    }
    cout << ans << endl;
    return 0;
}

