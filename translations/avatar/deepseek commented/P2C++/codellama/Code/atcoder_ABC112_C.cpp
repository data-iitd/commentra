
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

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
            cands.push_back({cx, cy, ls_xyh[0][2] + abs(cx - x0) + abs(cy - ls_xyh[0][1])});
        }
    }
    
    // Filter candidates to match the height of each point in ls_xyh
    for (int i = 1; i < n; i++) {
        int x = ls_xyh[i][0];
        int y = ls_xyh[i][1];
        int h = ls_xyh[i][2];
        cands.erase(remove_if(cands.begin(), cands.end(), [x, y, h](vector<int> cand) {
            return max(cand[2] - abs(cand[0] - x) - abs(cand[1] - y), 0) != h;
        }), cands.end());
    }
    
    // Return the coordinates of the center of the tower
    int xx = cands[0][0];
    int yy = cands[0][1];
    int hh = cands[0][2];
    return to_string(xx) + " " + to_string(yy) + " " + to_string(hh);
}

vector<vector<int>> readQuestion() {
    // Read input from stdin and parse the number of points and their coordinates and heights
    vector<string> ws = split(getline(cin), " ");
    int n = stoi(ws[0]);
    vector<vector<int>> ls_xyh;
    for (int j = 0; j < n; j++) {
        vector<string> xyh = split(getline(cin), " ");
        ls_xyh.push_back({stoi(xyh[0]), stoi(xyh[1]), stoi(xyh[2])});
    }
    return {n, ls_xyh};
}

vector<string> split(string s, string delimiter) {
    // Split a string into a vector of substrings
    vector<string> tokens;
    size_t pos = 0;
    while ((pos = s.find(delimiter)) != string::npos) {
        tokens.push_back(s.substr(0, pos));
        s.erase(0, pos + delimiter.length());
    }
    tokens.push_back(s);
    return tokens;
}

string getline(istream& is) {
    // Read a line from stdin
    string line;
    getline(is, line);
    return line;
}

int main() {
    // Read input, solve the problem, and print the result
    cout << solve(readQuestion()[0], readQuestion()[1]) << endl;
    return 0;
}

