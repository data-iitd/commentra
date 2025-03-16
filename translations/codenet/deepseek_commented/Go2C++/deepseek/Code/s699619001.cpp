#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Problem {
    int number, bonus;
};

// min returns the smaller of two integers.
int min(int a, int b) {
    return a < b ? a : b;
}

int main() {
    int D, G;
    cin >> D >> G;
    vector<Problem> problems(D);
    for (auto& p : problems) {
        cin >> p.number >> p.bonus;
    }

    int ans = 10000;
    for (int bit = 0; bit < (1 << D); ++bit) {
        int score = 0;
        int solved = 0;
        bool ok = false;
        for (int j = 0; j < D; ++j) {
            if (bit & (1 << j)) {
                score += (j + 1) * 100 * problems[j].number + problems[j].bonus;
                solved += problems[j].number;
            }
        }
        if (score < G) {
            int j;
            for (j = D - 1; j >= 0; --j) {
                if (!(bit & (1 << j))) {
                    break;
                }
            }
            for (int k = 0; k < problems[j].number; ++k) {
                score += (j + 1) * 100;
                ++solved;
                if (score >= G) {
                    ok = true;
                    break;
                }
            }
            if (!ok) {
                score += problems[j].bonus;
                if (score >= G) {
                    ok = true;
                }
            }
        } else {
            ok = true;
        }
        if (ok) {
            ans = min(ans, solved);
        }
    }
    cout << ans << endl;
    return 0;
}

