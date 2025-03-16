#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

vector<int> parseInputLine() {
    string line;
    getline(cin, line);
    stringstream ss(line);
    int num;
    vector<int> result;
    while (ss >> num) {
        result.push_back(num);
    }
    return result;
}

string solve(int n, vector<vector<int>> ls_xyh) {
    // Initialize the coordinates and height of the first building with a positive height
    int x0 = -1;
    for (int i = 0; i < n; ++i) {
        if (ls_xyh[i][2] > 0) {
            x0 = ls_xyh[i][0];
            break;
        }
    }
    
    // Generate candidate positions (cx, cy) with their corresponding heights based on the first building
    vector<vector<int>> cands;
    for (int cx = 0; cx <= 100; ++cx) {
        for (int cy = 0; cy <= 100; ++cy) {
            int h0 = ls_xyh[0][2] + abs(ls_xyh[0][0] - cx) + abs(ls_xyh[0][1] - cy);
            cands.push_back({cx, cy, h0});
        }
    }
    
    // Filter candidates based on the height constraints from the other buildings
    for (const auto& building : ls_xyh) {
        int x = building[0], y = building[1], h = building[2];
        vector<vector<int>> temp_cands;
        for (const auto& cand : cands) {
            int cx = cand[0], cy = cand[1], ch = cand[2];
            int calculated_h = max(ch - abs(cx - x) - abs(cy - y), 0);
            if (calculated_h == h) {
                temp_cands.push_back(cand);
            }
        }
        cands = temp_cands;
    }
    
    // Select the first valid candidate position and height
    int xx = cands[0][0], yy = cands[0][1], hh = cands[0][2];
    
    // Return the result as a space-separated string
    return to_string(xx) + " " + to_string(yy) + " " + to_string(hh);
}

int main() {
    // Read input from standard input and parse the number of buildings and their properties
    vector<int> input_line1 = parseInputLine();
    int n = input_line1[0];
    vector<vector<int>> ls_xyh;
    for (int i = 0; i < n; ++i) {
        vector<int> input_line = parseInputLine();
        ls_xyh.push_back(input_line);
    }
    
    // Execute the solve function with the input read from readQuestion and print the result
    string result = solve(n, ls_xyh);
    cout << result << endl;
    
    return 0;
}

