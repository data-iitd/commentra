#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int D, G;
    cin >> D >> G;

    vector<pair<int, int>> PC(D);
    for (int i = 0; i < D; i++) {
        cin >> PC[i].first >> PC[i].second;
    }

    int ans = 1000000000;
    for (int i = 0; i < (1 << D); i++) {
        int score = 0;
        int problem = 0;
        for (int j = 0; j < D; j++) {
            if (i & (1 << j)) {
                score += 100 * (j + 1) * PC[j].first + PC[j].second;
                problem += PC[j].first;
            }
        }
        if (score > G) {
            continue;
        }
        int left = G - score;
        for (int j = 0; j < D; j++) {
            if (i & (1 << j)) {
                continue;
            }
            if (left > 100 * (j + 1) * PC[j].first + PC[j].second) {
                continue;
            }
            int tmp = (left + (100 * (j + 1)) - 1) / (100 * (j + 1));
            ans = min(ans, problem + min(tmp, PC[j].first));
    }
    cout << ans << "\n";

    return 0;
}

