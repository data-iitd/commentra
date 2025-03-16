#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<int> solve(int n, vector<vector<int>> ls_xyh) {
    int x0 = -1;
    for (int i = 0; i < n; ++i) {
        if (ls_xyh[i][2] > 0) {
            x0 = ls_xyh[i][0];
            break;
        }
    }
    vector<vector<int>> cands;
    for (int cx = 0; cx <= 100; ++cx) {
        for (int cy = 0; cy <= 100; ++cy) {
            int h = ls_xyh[x0][2] + abs(ls_xyh[x0][0] - x0) + abs(ls_xyh[x0][1] - cy);
            cands.push_back({cx, cy, h});
        }
    }
    for (const auto& xyh : ls_xyh) {
        vector<vector<int>> temp_cands;
        for (const auto& cand : cands) {
            int ch = cand[2];
            int x = xyh[0], y = xyh[1], h = xyh[2];
            if (max(ch - abs(cand[0] - x) - abs(cand[1] - y), 0) == h) {
                temp_cands.push_back(cand);
            }
        }
        cands = temp_cands;
    }
    return cands[0];
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> ls_xyh(n, vector<int>(3));
    for (int i = 0; i < n; ++i) {
        cin >> ls_xyh[i][0] >> ls_xyh[i][1] >> ls_xyh[i][2];
    }
    vector<int> result = solve(n, ls_xyh);
    cout << result[0] << " " << result[1] << " " << result[2] << endl;
    return 0;
}

