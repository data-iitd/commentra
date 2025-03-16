#include <iostream>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

string solve(int n, vector<vector<int>>& ls_xyh) {
    int x0 = -1, y0 = -1, h0 = -1;
    for (int i = 0; i < n; i++) {
        if (ls_xyh[i][2] > 0) {
            x0 = ls_xyh[i][0];
            y0 = ls_xyh[i][1];
            h0 = ls_xyh[i][2];
            break;
        }
    }

    vector<tuple<int, int, int>> cands;
    for (int cx = 0; cx <= 100; cx++) {
        for (int cy = 0; cy <= 100; cy++) {
            cands.emplace_back(cx, cy, h0 + abs(cx - x0) + abs(cy - y0));
        }
    }

    for (const auto& point : ls_xyh) {
        int x = point[0], y = point[1], h = point[2];
        cands.erase(remove_if(cands.begin(), cands.end(),
            [&](const tuple<int, int, int>& c) {
                int cx = get<0>(c);
                int cy = get<1>(c);
                int ch = get<2>(c);
                return max(ch - abs(cx - x) - abs(cy - y), 0) != h;
            }), cands.end());
    }

    auto [xx, yy, hh] = cands[0];
    return to_string(xx) + " " + to_string(yy) + " " + to_string(hh);
}

pair<int, vector<vector<int>>> readQuestion() {
    int n;
    cin >> n;
    vector<vector<int>> ls_xyh(n, vector<int>(3));
    for (int j = 0; j < n; j++) {
        cin >> ls_xyh[j][0] >> ls_xyh[j][1] >> ls_xyh[j][2];
    }
    return {n, ls_xyh};
}

int main() {
    auto [n, ls_xyh] = readQuestion();
    cout << solve(n, ls_xyh) << endl;
    return 0;
}

// <END-OF-CODE>
