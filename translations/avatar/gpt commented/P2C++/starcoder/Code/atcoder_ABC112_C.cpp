#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solve(int n, vector<vector<int>> ls_xyh) {
    // Initialize the coordinates and height of the first building with a positive height
    int x0 = -1;
    for (int i = 0; i < n; i++) {
        if (ls_xyh[i][2] > 0) {
            x0 = ls_xyh[i][0];
            break;
        }
    }
    
    // Generate candidate positions (cx, cy) with their corresponding heights based on the first building
    vector<vector<int>> cands;
    for (int cx = 0; cx < 101; cx++) {
        for (int cy = 0; cy < 101; cy++) {
            int ch = abs(cx - x0) + abs(cy - ls_xyh[0][1]) + ls_xyh[0][2];
            cands.push_back({cx, cy, ch});
        }
    }
    
    // Filter candidates based on the height constraints from the other buildings
    for (int i = 1; i < n; i++) {
        int x = ls_xyh[i][0];
        int y = ls_xyh[i][1];
        int h = ls_xyh[i][2];
        cands.erase(remove_if(cands.begin(), cands.end(), [x, y, h](vector<int> cand) {
            return max(cand[2] - abs(cand[0] - x) - abs(cand[1] - y), 0)!= h;
        }), cands.end());
    }
    
    // Select the first valid candidate position and height
    vector<int> cand = cands[0];
    
    // Return the result as a space-separated string
    return to_string(cand[0]) + " " + to_string(cand[1]) + " " + to_string(cand[2]);
}

int main() {
    // Read input from standard input and parse the number of buildings and their properties
    int n;
    cin >> n;
    vector<vector<int>> ls_xyh(n);
    for (int j = 0; j < n; j++) {
        cin >> ls_xyh[j][0] >> ls_xyh[j][1] >> ls_xyh[j][2];
    }
    
    // Execute the solve function with the input read from readQuestion and print the result
    cout << solve(n, ls_xyh) << endl;
}

