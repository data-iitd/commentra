
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string solve(int n, vector<vector<int>> ls_xyh) {
    // Initialize the coordinates and height of the first building with a positive height
    int x0 = -1, y0 = -1, h0 = -1;
    for (int i = 0; i < n; i++) {
        if (ls_xyh[i][2] > 0) {
            x0 = ls_xyh[i][0];
            y0 = ls_xyh[i][1];
            h0 = ls_xyh[i][2];
            break;
        }
    }
    
    // Generate candidate positions (cx, cy) with their corresponding heights based on the first building
    vector<vector<int>> cands;
    for (int cx = 0; cx <= 100; cx++) {
        for (int cy = 0; cy <= 100; cy++) {
            cands.push_back({cx, cy, h0 + abs(cx - x0) + abs(cy - y0)});
        }
    }
    
    // Filter candidates based on the height constraints from the other buildings
    for (int i = 0; i < n; i++) {
        vector<vector<int>> new_cands;
        for (auto [cx, cy, ch] : cands) {
            if (max(ch - abs(cx - ls_xyh[i][0]) - abs(cy - ls_xyh[i][1]), 0) == ls_xyh[i][2]) {
                new_cands.push_back({cx, cy, ch});
            }
        }
        cands = new_cands;
    }
    
    // Select the first valid candidate position and height
    int xx = cands[0][0], yy = cands[0][1], hh = cands[0][2];
    
    // Return the result as a space-separated string
    return to_string(xx) + " " + to_string(yy) + " " + to_string(hh);
}

vector<vector<int>> readQuestion() {
    // Read input from standard input and parse the number of buildings and their properties
    int n;
    cin >> n;
    vector<vector<int>> ls_xyh(n, vector<int>(3));
    for (int j = 0; j < n; j++) {
        for (int k = 0; k < 3; k++) {
            cin >> ls_xyh[j][k];
        }
    }
    return ls_xyh;
}

int main() {
    // Execute the solve function with the input read from readQuestion and print the result
    cout << solve(readQuestion()) << endl;
}

Translate the above C++ code to Java and end with comment "