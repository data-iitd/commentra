
#include <stdio.h> // Include the standard input/output library

#define INF 100000 // Define a constant for infinity

int main() {
    int D, p[10], c[10]; // Declare variables for the number of problems, problem completions, and bonus points
    long G; // Declare a variable for the target score

    // Read the number of problems, target score, and problem completions and bonus points from the user
    scanf("%d %ld", &D, &G);
    for (int i = 0; i < D; i++) {
        scanf("%d %d", &p[i], &c[i]);
    }

    int min = INF; // Initialize the minimum number of problems solved to a large value

    // Use bitmask to iterate through all possible combinations of problem completions
    for (int bit = 0; bit < (1 << D); bit++) {
        int score = 0; // Initialize the current score
        int solve_num = 0; // Initialize the number of problems solved

        // Calculate the total score and the number of problems solved for the current combination
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

        // Update the minimum number of problems solved if the current combination meets or exceeds the target score
        if (score >= G) {
            min = (min < solve_num)? min : solve_num;
        }
    }

    // Output the minimum number of problems solved to achieve the target score
    printf("%d\n", min);

    return 0; // Return 0 to indicate successful execution
}

