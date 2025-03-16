
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> lst(N);
    for (int i = 0; i < N; i++) {
        cin >> lst[i];
        if (lst[i] == 0) {
            K--;
        }
    }

    vector<int> lst_p, lst_m;
    for (int i = 0; i < N; i++) {
        if (lst[i] > 0) {
            lst_p.push_back(lst[i]);
        } else if (lst[i] < 0) {
            lst_m.push_back(lst[i]);
        }
    }

    sort(lst_p.begin(), lst_p.end());
    sort(lst_m.begin(), lst_m.end());

    int p = 0, m = 0;
    int lastx = lst_p.size(), lasty = lst_m.size();

    int ans = 1e9;
    for (int j = 0; j <= K; j++) {
        if (j > lastx || K - j > lasty) {
            continue;
        }
        if (j == 0) {
            p = 0;
        } else {
            p = lst_p[j - 1];
        }
        if (K - j == 0) {
            m = 0;
        } else {
            m = lst_m[lasty - (K - j)];
        }
        ans = min(ans, 2 * p + abs(m), p + 2 * abs(m));
    }

    cout << ans << endl;

    return 0;
}
