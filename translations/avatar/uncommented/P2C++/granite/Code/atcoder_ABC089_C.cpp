
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<string> S(N);
    for (int i = 0; i < N; i++) {
        cin >> S[i];
    }
    vector<int> march_count(5, 0);
    vector<char> march = {'M', 'A', 'R', 'C', 'H'};
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 5; j++) {
            if (S[i][0] == march[j] || S[i][0] == march[j] - 32) {
                march_count[j]++;
                break;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = i + 1; j < 4; j++) {
            for (int k = j + 1; k < 5; k++) {
                ans += march_count[i] * march_count[j] * march_count[k];
            }
        }
    }
    cout << ans << endl;
    return 0;
}
// END-OF-CODE