#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 100000;

int main() {
    // Read the number of problems D and the goal score G
    int D;
    long long G;
    cin >> D >> G;

    // Vectors to store the number of problems and their corresponding scores
    vector<int> p(D); // p[i] = number of problems for the i-th problem set
    vector<int> c(D); // c[i] = additional score for the i-th problem set

    // Read the number of problems and additional scores for each problem set
    for (int i = 0; i < D; i++) {
        cin >> p[i] >> c[i];
    }

    // Initialize the minimum number of problems solved to infinity
    int min_problems = INF;

    // Iterate through all possible combinations of problem sets using bit masking
    for (int bit = 0; bit < (1 << D); bit++) {
        long long score = 0; // Total score achieved with the current combination
        int solve_num = 0; // Total number of problems solved with the current combination

        // Calculate the score and number of problems solved for the current combination
        for (int i = 0; i < D; i++) {
            if (bit & (1 << i)) { // Check if the i-th problem set is included
                score += 100 * (i + 1) * p[i] + c[i]; // Update score
                solve_num += p[i]; // Update number of problems solved
            }
        }

        // If the current score is less than the goal score G
        if (score < G) {
            loop: // Label for breaking out of the nested loop
            for (int i = D - 1; i >= 0; i--) { // Iterate through problem sets in reverse
                if (!(bit & (1 << i))) { // Check if the i-th problem set is not included
                    // Attempt to solve additional problems from this set
                    for (int j = 0; j < p[i]; j++) {
                        score += 100 * (i + 1); // Increase score by the value of the problem
                        solve_num++; // Increment the number of problems solved
                        if (score >= G) { // If the score meets or exceeds the goal
                            break loop; // Exit the loop
                        }
                    }
                }
            }
        }

        // If the score meets or exceeds the goal, update the minimum number of problems solved
        if (score >= G) {
            min_problems = min(min_problems, solve_num); // Update min if a better solution is found
        }
    }

    // Output the minimum number of problems solved to achieve the goal score
    cout << min_problems << endl;

    return 0;
}

// <END-OF-CODE>
