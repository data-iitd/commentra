#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

// Function to solve the problem
string solve(int n, vector<vector<int>>& ls_xyh) {
    int x0 = -1, y0 = -1, h0 = -1;

    // Iterate through the list ls_xyh to find the point with the highest height
    for (int i = 0; i < n; i++) {
        if (ls_xyh[i][2] > 0) {  // Check if the height is positive
            x0 = ls_xyh[i][0];
            y0 = ls_xyh[i][1];
            h0 = ls_xyh[i][2];
            break;
        }
    }

    // Generate a list of candidate points based on the given height and the position of x0, y0
    vector<tuple<int, int, int>> cands;
    for (int cx = 0; cx <= 100; cx++) {
        for (int cy = 0; cy <= 100; cy++) {
            cands.emplace_back(cx, cy, h0 + abs(cx - x0) + abs(cy - y0));
        }
    }

    // Filter out the invalid candidate points based on the given height
    for (const auto& point : ls_xyh) {
        int x = point[0], y = point[1], h = point[2];
        cands.erase(remove_if(cands.begin(), cands.end(),
            [x, y, h](const tuple<int, int, int>& c) {
                int cx = get<0>(c);
                int cy = get<1>(c);
                int ch = get<2>(c);
                return max(ch - abs(cx - x) - abs(cy - y), 0) != h;
            }), cands.end());
    }

    // Find the point with the minimum height among the valid candidates
    auto best_candidate = *min_element(cands.begin(), cands.end(),
        [](const tuple<int, int, int>& a, const tuple<int, int, int>& b) {
            return get<2>(a) < get<2>(b);
        });

    // Return the solution as a string
    return to_string(get<0>(best_candidate)) + " " + to_string(get<1>(best_candidate)) + " " + to_string(get<2>(best_candidate));
}

// Function to read the question and return the problem data
pair<int, vector<vector<int>>> readQuestion() {
    int n;
    cin >> n;

    vector<vector<int>> ls_xyh(n, vector<int>(3));
    for (int i = 0; i < n; i++) {
        cin >> ls_xyh[i][0] >> ls_xyh[i][1] >> ls_xyh[i][2];
    }

    return {n, ls_xyh};
}

// Main function to call the solve function and print the result
int main() {
    // Call the readQuestion function to get the problem data
    auto data = readQuestion();

    // Call the solve function to get the solution
    string solution = solve(data.first, data.second);

    // Print the solution
    cout << solution << endl;

    return 0;
}

// <END-OF-CODE>
