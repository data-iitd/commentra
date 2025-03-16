#include <iostream>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

string solve(int n, vector<vector<int>>& ls_xyh) {
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
    vector<tuple<int, int, int>> cands;
    for (int cx = 0; cx <= 100; cx++) {
        for (int cy = 0; cy <= 100; cy++) {
            cands.emplace_back(cx, cy, h0 + abs(cx - x0) + abs(cy - y0));
        }
    }
    
    // Filter candidates based on the height constraints from the other buildings
    for (const auto& building : ls_xyh) {
        int x = building[0], y = building[1], h = building[2];
        cands.erase(remove_if(cands.begin(), cands.end(), [&](const tuple<int, int, int>& c) {
            int cx = get<0>(c), cy = get<1>(c), ch = get<2>(c);
            return max(ch - abs(cx - x) - abs(cy - y), 0) != h;
        }), cands.end());
    }
    
    // Select the first valid candidate position and height
    auto [xx, yy, hh] = cands[0];
    
    // Return the result as a space-separated string
    return to_string(xx) + " " + to_string(yy) + " " + to_string(hh);
}

pair<int, vector<vector<int>>> readQuestion() {
    // Read input from standard input and parse the number of buildings and their properties
    int n;
    cin >> n;
    vector<vector<int>> ls_xyh(n, vector<int>(3));
    for (int j = 0; j < n; j++) {
        cin >> ls_xyh[j][0] >> ls_xyh[j][1] >> ls_xyh[j][2];
    }
    return {n, ls_xyh};
}

int main() {
    // Execute the solve function with the input read from readQuestion and print the result
    auto [n, ls_xyh] = readQuestion();
    cout << solve(n, ls_xyh) << endl;
    return 0;
}

// <END-OF-CODE>
