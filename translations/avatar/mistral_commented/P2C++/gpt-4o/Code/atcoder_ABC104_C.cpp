#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    // Define input variables
    int D, G;
    cin >> D >> G;

    // Initialize vector of problems with their respective capacities
    vector<pair<int, int>> PC(D);
    for (int i = 0; i < D; ++i) {
        cin >> PC[i].first >> PC[i].second;
    }

    // Initialize variable for the best answer
    int ans = INT_MAX;

    // Loop through all possible combinations of problems
    for (int i = 0; i < (1 << D); ++i) {
        // Initialize variables for current combination
        int score = 0;
        int problem = 0;

        // Calculate score for current combination
        for (int j = 0; j < D; ++j) {
            // If problem j is included in current combination
            if ((i >> j) & 1) {
                // Add score for problem j to the total score
                score += 100 * (j + 1) * PC[j].first + PC[j].second;
                // Add capacity of problem j to the total problem
                problem += PC[j].first;
            }
        }

        // If score for current combination is greater than goal G, skip to next combination
        if (score > G) {
            continue;
        }

        // Calculate remaining capacity to be covered
        int left = G - score;

        // Loop through all problems and check if they can be included in the solution
        for (int j = 0; j < D; ++j) {
            // If problem j is already included in current combination, skip it
            if ((i >> j) & 1) {
                continue;
            }

            // Check if including problem j can cover the remaining capacity
            if (left > 100 * (j + 1) * PC[j].first + PC[j].second) {
                continue;
            } else {
                // Calculate the number of instances of problem j that can be included
                int tmp = (left + (100 * (j + 1) - 1)) / (100 * (j + 1));
                // Update the answer if including more instances of problem j results in a better solution
                ans = min(ans, problem + min(tmp, PC[j].first));
            }
        }
    }

    // Print the answer
    cout << ans << endl;

    return 0;
}

// <END-OF-CODE>
