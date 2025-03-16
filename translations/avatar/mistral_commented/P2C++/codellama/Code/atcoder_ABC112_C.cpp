#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Function to solve the problem
string solve(int n, vector<vector<int>> ls_xyh) {
    // Initialize x0 as None
    int x0 = -1;

    // Iterate through the list ls_xyh to find the point with the highest height
    for (int i = 0; i < n; i++) {
        if (ls_xyh[i][2] > 0) {  // Check if the height is positive
            x0 = ls_xyh[i][0];  // Assign x0
            break;
        }
    }

    // Generate a list of candidate points based on the given height and the position of x0
    vector<vector<int>> cands;
    for (int cx = 0; cx < 101; cx++) {
        for (int cy = 0; cy < 101; cy++) {
            cands.push_back({cx, cy, ls_xyh[0][2] + abs(cx - x0) + abs(cy - ls_xyh[0][1])});
        }
    }

    // Filter out the invalid candidate points based on the given height
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < cands.size(); j++) {
            if (max(cands[j][2] - abs(cands[j][0] - ls_xyh[i][0]) - abs(cands[j][1] - ls_xyh[i][1]), 0) == ls_xyh[i][2]) {
                cands.erase(cands.begin() + j);
                j--;
            }
        }
    }

    // Find the point with the minimum height among the valid candidates
    int xx = cands[0][0];
    int yy = cands[0][1];
    int hh = cands[0][2];

    // Return the solution as a string
    return to_string(xx) + " " + to_string(yy) + " " + to_string(hh);
}

// Function to read the question and return the problem data
vector<vector<int>> readQuestion() {
    // Read the first line to get the number of points
    string s;
    getline(cin, s);
    stringstream ss(s);
    int n;
    ss >> n;

    // Read the second line to get the list of points
    vector<vector<int>> ls_xyh;
    for (int i = 0; i < n; i++) {
        getline(cin, s);
        stringstream ss(s);
        int x, y, h;
        ss >> x >> y >> h;
        ls_xyh.push_back({x, y, h});
    }

    // Return the problem data as a tuple (number of points, list of points)
    return ls_xyh;
}

// Main function to call the solve function and print the result
int main() {
    // Call the readQuestion function to get the problem data
    vector<vector<int>> data = readQuestion();

    // Call the solve function to get the solution
    string solution = solve(data.size(), data);

    // Print the solution
    cout << solution << endl;

    return 0;
}

