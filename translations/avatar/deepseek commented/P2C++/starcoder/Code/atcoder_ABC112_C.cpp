
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Read input from stdin and parse the number of points and their coordinates and heights
    int n;
    cin >> n;
    vector<vector<int>> ls_xyh(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> ls_xyh[i][j];
        }
    }
    
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
    vector<vector<int>> cands(101 * 101);
    for (int cx = 0; cx < 101; cx++) {
        for (int cy = 0; cy < 101; cy++) {
            cands[cx * 101 + cy] = {cx, cy, ls_xyh[0][2] + abs(cx - x0) + abs(cy - ls_xyh[0][1])};
        }
    }
    
    // Filter candidates to match the height of each point in ls_xyh
    for (int i = 1; i < n; i++) {
        int x = ls_xyh[i][0];
        int y = ls_xyh[i][1];
        int h = ls_xyh[i][2];
        for (int j = 0; j < 101 * 101; j++) {
            int cx = cands[j][0];
            int cy = cands[j][1];
            int ch = cands[j][2];
            cands[j][2] = max(ch - abs(cx - x) - abs(cy - y), 0);
        }
    }
    
    // Return the coordinates of the center of the tower
    int xx = cands[0][0];
    int yy = cands[0][1];
    int hh = cands[0][2];
    cout << xx << " " << yy << " " << hh << endl;
    return 0;
}

