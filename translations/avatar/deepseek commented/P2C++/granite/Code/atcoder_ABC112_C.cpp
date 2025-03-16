

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string solve(int n, vector<vector<int>> ls_xyh) {
    // Initialize x0 to None
    int x0 = -1;
    
    // Find the point with a positive height
    for (int i = 0; i < n; i++) {
        if (ls_xyh[i][2] > 0) {
            x0 = ls_xyh[i][0];
            break;
        }
    }
    
    // Generate candidate points within a 101x101 grid
    vector<vector<int>> cands;
    for (int cx = 0; cx < 101; cx++) {
        for (int cy = 0; cy < 101; cy++) {
            int h0 = ls_xyh[0][2] + abs(cx - x0) + abs(cy - ls_xyh[0][1]);
            cands.push_back({cx, cy, h0});
        }
    }
    
    // Filter candidates to match the height of each point in ls_xyh
    for (int i = 0; i < n; i++) {
        vector<vector<int>> new_cands;
        for (auto cand : cands) {
            int x = cand[0], y = cand[1], h = cand[2];
            if (max(h - abs(x - ls_xyh[i][0]) - abs(y - ls_xyh[i][1]), 0) == ls_xyh[i][2]) {
                new_cands.push_back(cand);
            }
        }
        cands = new_cands;
    }
    
    // Return the coordinates of the center of the tower
    int xx = cands[0][0], yy = cands[0][1], hh = cands[0][2];
    return to_string(xx) + " " + to_string(yy) + " " + to_string(hh);
}

vector<vector<int>> readQuestion() {
    // Read input from stdin and parse the number of points and their coordinates and heights
    int n;
    cin >> n;
    vector<vector<int>> ls_xyh(n, vector<int>(3));
    for (int j = 0; j < n; j++) {
        cin >> ls_xyh[j][0] >> ls_xyh[j][1] >> ls_xyh[j][2];
    }
    return ls_xyh;
}

int main() {
    // Read input, solve the problem, and print the result
    vector<vector<int>> ls_xyh = readQuestion();
    cout << solve(ls_xyh.size(), ls_xyh) << endl;
    return 0;
}

