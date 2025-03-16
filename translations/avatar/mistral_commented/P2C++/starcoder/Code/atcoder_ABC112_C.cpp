#include <bits/stdc++.h>

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

    // Generate a list of candidate points based on the given height and the position of x0, y0
    vector<vector<int>> cands = vector<vector<int>>();
    for (int cx = 0; cx < 101; cx++) {
        for (int cy = 0; cy < 101; cy++) {
            int ch = ls_xyh[0][2] + abs(cx - x0) + abs(cy - ls_xyh[0][1]);
            cands.push_back({cx, cy, ch});
        }
    }

    // Filter out the invalid candidate points based on the given height
    for (int i = 1; i < n; i++) {
        int x = ls_xyh[i][0];
        int y = ls_xyh[i][1];
        int h = ls_xyh[i][2];
        for (int j = 0; j < cands.size(); j++) {
            int cx = cands[j][0];
            int cy = cands[j][1];
            int ch = cands[j][2];
            cands[j][2] = max(ch - abs(cx - x) - abs(cy - y), 0);
        }
    }

    // Find the point with the minimum height among the valid candidates
    int min_h = 1000000000;
    for (int i = 0; i < cands.size(); i++) {
        if (cands[i][2] < min_h) {
            min_h = cands[i][2];
            x0 = cands[i][0];
            y0 = cands[i][1];
        }
    }

    // Return the solution as a string
    return to_string(x0) + " " + to_string(y0) + " " + to_string(min_h);
}

// Function to read the question and return the problem data
tuple<int, vector<vector<int>>> readQuestion() {
    // Read the first line to get the number of points
    string line;
    getline(cin, line);
    istringstream iss(line);
    int n;
    iss >> n;

    // Read the second line to get the list of points
    vector<vector<int>> ls_xyh = vector<vector<int>>();
    for (int j = 0; j < n; j++) {
        string line;
        getline(cin, line);
        istringstream iss(line);
        int x, y, h;
        iss >> x >> y >> h;
        ls_xyh.push_back({x, y, h});
    }

    // Return the problem data as a tuple (number of points, list of points)
    return make_tuple(n, ls_xyh);
}

// Main function to call the solve function and print the result
int main() {
    // Call the readQuestion function to get the problem data
    tuple<int, vector<vector<int>>> data = readQuestion();

    // Call the solve function to get the solution
    string solution = solve(get<0>(data), get<1>(data));

    // Print the solution
    cout << solution << endl;

    return 0;
}

