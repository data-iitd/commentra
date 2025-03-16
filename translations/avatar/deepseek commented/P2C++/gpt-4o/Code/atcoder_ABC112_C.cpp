#include <iostream>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

string solve(int n, vector<vector<int>>& ls_xyh) {
    // Initialize x0 to -1 (indicating not found)
    int x0 = -1, y0 = -1, h0 = -1;

    // Find the point with a positive height
    for (int i = 0; i < n; i++) {
        if (ls_xyh[i][2] > 0) {
            x0 = ls_xyh[i][0];
            y0 = ls_xyh[i][1];
            h0 = ls_xyh[i][2];
            break;
        }
    }

    // Generate candidate points within a 101x101 grid
    vector<tuple<int, int, int>> cands;
    for (int cx = 0; cx <= 100; cx++) {
        for (int cy = 0; cy <= 100; cy++) {
            cands.emplace_back(cx, cy, h0 + abs(cx - x0) + abs(cy - y0));
        }
    }

    // Filter candidates to match the height of each point in ls_xyh
    for (const auto& point : ls_xyh) {
        int x = point[0], y = point[1], h = point[2];
        vector<tuple<int, int, int>> new_cands;
        for (const auto& [cx, cy, ch] : cands) {
            if (max(ch - abs(cx - x) - abs(cy - y), 0) == h) {
                new_cands.emplace_back(cx, cy, ch);
            }
        }
        cands = move(new_cands);
    }

    // Return the coordinates of the center of the tower
    auto [xx, yy, hh] = cands[0];
    return to_string(xx) + " " + to_string(yy) + " " + to_string(hh);
}

pair<int, vector<vector<int>>> readQuestion() {
    // Read input from stdin and parse the number of points and their coordinates and heights
    int n;
    cin >> n;
    vector<vector<int>> ls_xyh(n, vector<int>(3));
    for (int j = 0; j < n; j++) {
        cin >> ls_xyh[j][0] >> ls_xyh[j][1] >> ls_xyh[j][2];
    }
    return {n, ls_xyh};
}

int main() {
    // Read input, solve the problem, and print the result
    auto [n, ls_xyh] = readQuestion();
    cout << solve(n, ls_xyh) << endl;
    return 0;
}

// <END-OF-CODE>
