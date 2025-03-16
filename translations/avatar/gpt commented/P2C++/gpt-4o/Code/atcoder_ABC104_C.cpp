#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    // Read the number of problems (D) and the maximum score (G) from input
    int D, G;
    cin >> D >> G;

    // Read the problem data, each containing the number of problems and the score for that problem
    vector<pair<int, int>> PC(D);
    for (int i = 0; i < D; ++i) {
        cin >> PC[i].first >> PC[i].second;
    }

    // Initialize the answer to a large number (infinity)
    int ans = 1e9;

    // Iterate through all possible combinations of problems (2^D combinations)
    for (int i = 0; i < (1 << D); ++i) {
        int score = 0;  // Initialize the current score
        int problem = 0;  // Initialize the count of problems solved

        // Calculate the score and number of problems solved for the current combination
        for (int j = 0; j < D; ++j) {
            if (i & (1 << j)) {  // Check if the j-th problem is included in the combination
                score += 100 * (j + 1) * PC[j].first + PC[j].second;  // Update score based on the problem's data
                problem += PC[j].first;  // Update the number of problems solved
            }
        }

        // If the current score exceeds the maximum score (G), skip to the next combination
        if (score > G) {
            continue;
        }

        // Calculate the remaining score that can be achieved
        int left = G - score;

        // Check for each problem that is not included in the current combination
        for (int j = 0; j < D; ++j) {
            if (i & (1 << j)) {  // Skip if the problem is already included
                continue;
            }

            // If the remaining score is greater than the score that can be achieved with this problem, skip
            if (left > 100 * (j + 1) * PC[j].first + PC[j].second) {
                continue;
            } else {
                // Calculate the minimum number of additional problems needed to reach the remaining score
                int tmp = (left + (100 * (j + 1)) - 1) / (100 * (j + 1));
                // Update the answer with the minimum number of problems solved
                ans = min(ans, problem + min(tmp, PC[j].first));
            }
        }
    }

    // Print the minimum number of problems solved to achieve the maximum score
    cout << ans << endl;

    return 0;
}

// <END-OF-CODE>
