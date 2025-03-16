#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <limits>

using namespace std;

int main() {
    int D, G;
    cin >> D >> G;
    vector<tuple<int, int>> PC(D);
    for (int i = 0; i < D; ++i) {
        int a, b;
        cin >> a >> b;
        PC[i] = make_tuple(a, b);
    }

    int ans = numeric_limits<int>::max();
    for (int i = 0; i < (1 << D); ++i) {
        int score = 0;
        int problem = 0;
        for (int j = 0; j < D; ++j) {
            if ((i >> j) & 1) {
                score += 100 * (j + 1) * get<0>(PC[j]) + get<1>(PC[j]);
                problem += get<0>(PC[j]);
            }
        }
        if (score > G) {
            continue;
        }
        int left = G - score;
        for (int j = 0; j < D; ++j) {
            if ((i >> j) & 1) {
                continue;
            }
            if (left > 100 * (j + 1) * get<0>(PC[j]) + get<1>(PC[j])) {
                continue;
            } else {
                int tmp = (left + (100 * (j + 1)) - 1) / (100 * (j + 1));
                ans = min(ans, problem + min(tmp, get<0>(PC[j])));
            }
        }
    }
    cout << ans << endl;

    return 0;
}
// <END-OF-CODE>
