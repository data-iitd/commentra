#include <bits/stdc++.h>

using namespace std;

// Define a constant for infinity (a large number)
const int INF = 100000;

int main() {
    // Create a new instance of the C++ standard library's input stream class
    // and associate it with the standard input stream
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Create a new instance of the C++ standard library's input stream class
    // and associate it with the standard input stream
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Read the number of problems D and the goal score G
    int D, G;
    cin >> D >> G;

    // Arrays to store the number of problems and their corresponding scores
    int p[D]; // p[i] = number of problems for the i-th problem set
    int c[D]; // c[i] = additional score for the i-th problem set

    // Read the number of problems and additional scores for each problem set
    for (int i = 0; i < D; i++) {
        cin >> p[i] >> c[i];
    }

    // Initialize the minimum number of problems solved to infinity
    int min = INF;

    // Iterate through all possible combinations of problem sets using bit masking
    for (int bit = 0; bit < (1 << D); bit++) {
        int score = 0; // Total score achieved with the current combination
        int solve_num = 0; // Total number of problems solved with the current combination

        // Calculate the score and number of problems solved for the current combination
        for (int i = 0; i < D; i++) {
            if ((bit & (1 << i))!= 0) { // Check if the i-th problem set is included
                score += 100 * (i + 1) * p[i] + c[i]; // Update score
                solve_num += p[i]; // Update number of problems solved
            }
        }

        // If the current score is less than the goal score G
        if (score < G) {
            loop: // Label for breaking out of the nested loop
            for (int i = D - 1; i >= 0; i--) { // Iterate through problem sets in reverse
                if ((bit & (1 << i)) == 0) { // Check if the i-th problem set is not included
                    // Attempt to solve additional problems from this set
                    for (int j = 0; j < p[i] - 1; j++) {
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
            min = min < solve_num? min : solve_num; // Update min if a better solution is found
        }
    }

    // Output the minimum number of problems solved to achieve the goal score
    cout << min << endl;

    // Flush the standard output stream to forcefully output the result
    cout.flush();

    // Return from main function
    return 0;
}

