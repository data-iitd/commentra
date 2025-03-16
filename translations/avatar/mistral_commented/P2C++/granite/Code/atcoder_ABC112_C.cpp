
#include <iostream>
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
            x0 = i;  // Assign x0 as the index of the point with the highest height
            break;
        }
    }

    // Generate a list of candidate points based on the given height and the position of x0
    vector<vector<int>> cands;
    for (int cx = 0; cx <= 100; cx++) {
        for (int cy = 0; cy <= 100; cy++) {
            int h0 = ls_xyh[x0][2] + abs(cx - ls_xyh[x0][0]) + abs(cy - ls_xyh[x0][1]);
            cands.push_back({cx, cy, h0});
        }
    }

    // Filter out the invalid candidate points based on the given height
    for (int i = 0; i < n; i++) {
        vector<vector<int>> new_cands;
        for (auto cand : cands) {
            if (max(cand[2] - abs(cand[0] - ls_xyh[i][0]) - abs(cand[1] - ls_xyh[i][1]), 0) == ls_xyh[i][2]) {
                new_cands.push_back(cand);
            }
        }
        cands = new_cands;
    }

    // Find the point with the minimum height among the valid candidates
    int xx = cands[0][0], yy = cands[0][1], hh = cands[0][2];

    // Return the solution as a string
    return to_string(xx) + " " + to_string(yy) + " " + to_string(hh);
}

// Function to read the question and return the problem data
tuple<int, vector<vector<int>>> readQuestion() {
    // Read the first line to get the number of points
    int n;
    cin >> n;

    // Read the second line to get the list of points
    vector<vector<int>> ls_xyh(n, vector<int>(3));
    for (int j = 0; j < n; j++) {
        cin >> ls_xyh[j][0] >> ls_xyh[j][1] >> ls_xyh[j][2];
    }

    // Return the problem data as a tuple (number of points, list of points)
    return make_tuple(n, ls_xyh);
}

// Main function to call the solve function and print the result
int main() {
    // Call the readQuestion function to get the problem data
    auto data = readQuestion();

    // Call the solve function to get the solution
    string solution = solve(get<0>(data), get<1>(data));

    // Print the solution
    cout << solution << endl;

    return 0;
}

