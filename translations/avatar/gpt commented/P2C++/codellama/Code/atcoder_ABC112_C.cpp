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
            cands.push_back({cx, cy, ls_xyh[0][2] + abs(cx - x0) + abs(cy - ls_xyh[0][1])});
        }
    }
    
    // Filter candidates based on the height constraints from the other buildings
    for (int i = 1; i < n; i++) {
        int x = ls_xyh[i][0];
        int y = ls_xyh[i][1];
        int h = ls_xyh[i][2];
        cands = vector<vector<int>>(
            filter(
                [x, y, h](vector<int> cand) {
                    return max(cand[2] - abs(cand[0] - x) - abs(cand[1] - y), 0) == h;
                },
                cands
            )
        );
    }
    
    // Select the first valid candidate position and height
    int xx = cands[0][0];
    int yy = cands[0][1];
    int hh = cands[0][2];
    
    // Return the result as a space-separated string
    return xx + " " + yy + " " + to_string(hh);
}

vector<vector<int>> readQuestion() {
    // Read input from standard input and parse the number of buildings and their properties
    vector<string> ws = split(getline(cin), " ");
    int n = stoi(ws[0]);
    vector<vector<int>> ls_xyh(n);
    for (int i = 0; i < n; i++) {
        ws = split(getline(cin), " ");
        ls_xyh[i] = {stoi(ws[0]), stoi(ws[1]), stoi(ws[2])};
    }
    return {n, ls_xyh};
}

vector<string> split(string s, string delimiter) {
    // Split a string into a vector of substrings based on a delimiter
    size_t pos = 0;
    string token;
    vector<string> result;
    while ((pos = s.find(delimiter)) != string::npos) {
        token = s.substr(0, pos);
        result.push_back(token);
        s.erase(0, pos + delimiter.length());
    }
    result.push_back(s);
    return result;
}

string getline(istream& is) {
    // Read a line from standard input and return it as a string
    string line;
    getline(is, line);
    return line;
}

int main() {
    // Execute the solve function with the input read from readQuestion and print the result
    cout << solve(readQuestion()[0], readQuestion()[1]) << endl;
    return 0;
}

