#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

string solve(int n, vector<vector<int>> ls_xyh) {
    // Initialize x0 to None
    int x0 = -1;
    
    // Find the point with a positive height
    for (int i = 0; i < n; ++i) {
        if (ls_xyh[i][2] > 0) {
            x0 = ls_xyh[i][0];
            break;
        }
    }
    
    // Generate candidate points within a 101x101 grid
    vector<vector<int>> cands;
    for (int cx = 0; cx < 101; ++cx) {
        for (int cy = 0; cy < 101; ++cy) {
            int hh = ls_xyh[x0][2] + abs(cx - ls_xyh[x0][0]) + abs(cy - ls_xyh[x0][1]);
            cands.push_back({cx, cy, hh});
        }
    }
    
    // Filter candidates to match the height of each point in ls_xyh
    for (const auto& point : ls_xyh) {
        int x = point[0], y = point[1], h = point[2];
        vector<vector<int>> new_cands;
        for (const auto& cand : cands) {
            int cx = cand[0], cy = cand[1], ch = cand[2];
            if (max(ch - abs(cx - x) - abs(cy - y), 0) == h) {
                new_cands.push_back(cand);
            }
        }
        cands = new_cands;
    }
    
    // Return the coordinates of the center of the tower
    int xx = cands[0][0], yy = cands[0][1], hh = cands[0][2];
    return to_string(xx) + " " + to_string(yy) + " " + to_string(hh);
}

int main() {
    // Read input and parse the number of points and their coordinates and heights
    int n;
    cin >> n;
    vector<vector<int>> ls_xyh(n, vector<int>(3));
    for (int i = 0; i < n; ++i) {
        cin >> ls_xyh[i][0] >> ls_xyh[i][1] >> ls_xyh[i][2];
    }
    
    // Solve the problem and print the result
    cout << solve(n, ls_xyh) << endl;
    
    return 0;
}

