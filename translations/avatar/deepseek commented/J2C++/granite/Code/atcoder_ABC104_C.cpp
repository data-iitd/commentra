
#include <iostream> // Including the necessary libraries for input/output operations
#include <algorithm> // Including the algorithm library for sorting and other operations

using namespace std;

const int INF = 100000; // Defining a constant for infinity

int main() {
    int D, G; // Declaring variables to store the number of problems and the target score
    cin >> D >> G; // Reading the number of problems and the target score from the input

    int p[D], c[D]; // Arrays to store the number of problems completed and the bonus points for each problem
    for (int i = 0; i < D; i++) {
        cin >> p[i] >> c[i]; // Reading the number of problems completed and the bonus points for each problem
    }

    int min = INF; // Initializing the minimum number of problems solved to a large value

    // Using bitmask to iterate through all possible combinations of problem completions
    for (int bit = 0; bit < (1 << D); bit++) {
        int score = 0; // Initializing the current score
        int solve_num = 0; // Initializing the number of problems solved

        // Calculating the total score and the number of problems solved for the current combination
        for (int i = 0; i < D; i++) {
            if ((bit & (1 << i))!= 0) {
                score += 100 * (i + 1) * p[i] + c[i];
                solve_num += p[i];
            }
        }

        // If the score is less than the target, try to maximize the score by completing remaining problems
        if (score < G) {
            for (int i = D - 1; i >= 0; i--) {
                if ((bit & (1 << i)) == 0) {
                    for (int j = 0; j < p[i] - 1; j++) {
                        score += 100 * (i + 1);
                        solve_num++;
                        if (score >= G) {
                            break;
                        }
                    }
                }
            }
        }

        // Updating the minimum number of problems solved if the current combination meets or exceeds the target score
        if (score >= G) {
            min = min(min, solve_num);
        }
    }

    // Output the minimum number of problems solved to achieve the target score
    cout << min << endl; // Outputting the minimum number of problems solved

    return 0; // Returning 0 to indicate successful execution of the program
}

