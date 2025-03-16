#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Function to solve the problem
string solve(int n, vector<vector<int>> ls_xyh) {
    // Initialize x0 as None
    int x0 = -1;

    // Iterate through the list ls_xyh to find the point with the highest height
    for (int i = 0; i < n; ++i) {
        if (ls_xyh[i][2] > 0) {  // Check if the height is positive
            x0 = i;  // Assign x0
            break;
        }
    }

    // Generate a list of candidate points based on the given height and the position of x0, y0
    vector<vector<int>> cands;
    for (int cx = 0; cx <= 100; ++cx) {
        for (int cy = 0; cy <= 100; ++cy) {
            int ch = ls_xyh[x0][2] + abs(cx - ls_xyh[x0][0]) + abs(cy - ls_xyh[x0][1]);
            cands.push_back({cx, cy, ch});
        }
    }

    // Filter out the invalid candidate points based on the given height
    vector<vector<int>> valid_cands;
    for (const auto& cand : cands) {
        bool valid = true;
        for (const auto& point : ls_xyh) {
            int dist = abs(cand[0] - point[0]) + abs(cand[1] - point[1]);
            if (max(cand[2] - dist, 0) != point[2]) {
                valid = false;
                break;
            }
        }
        if (valid) {
            valid_cands.push_back(cand);
        }
    }

    // Find the point with the minimum height among the valid candidates
    int xx = valid_cands[0][0], yy = valid_cands[0][1], hh = valid_cands[0][2];

    // Return the solution as a string
    return to_string(xx) + " " + to_string(yy) + " " + to_string(hh);
}

// Function to read the question and return the problem data
vector<vector<int>> readQuestion() {
    // Read the first line to get the number of points
    int n;
    cin >> n;

    // Read the second line to get the list of points
    vector<vector<int>> ls_xyh(n, vector<int>(3));
    for (int i = 0; i < n; ++i) {
        cin >> ls_xyh[i][0] >> ls_xyh[i][1] >> ls_xyh[i][2];
    }

    // Return the problem data as a vector of vectors
    return ls_xyh;
}

// Main function to call the solve function and print the result
int main() {
    // Call the readQuestion function to get the problem data
    vector<vector<int>> ls_xyh = readQuestion();

    // Call the solve function to get the solution
    string solution = solve(ls_xyh.size(), ls_xyh);

    // Print the solution
    cout << solution << endl;

    return 0;
}
