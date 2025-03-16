#include <stdio.h>
#include <stdlib.h>

// Define a custom problem struct to store number and bonus
typedef struct {
    int number, bonus;
} problem;

// Function to find minimum of two integers
int min(int a, int b) {
    return a >= b ? b : a;
}

// Main function starts the execution
int main() {
    // Initialize variables D and G to read input from user
    int D, G;
    scanf("%d %d", &D, &G);

    // Create a slice of problem structs with size D
    problem *problems = (problem *)malloc(D * sizeof(problem));

    // Read number and bonus for each problem from user and store it in the slice
    for (int i = 0; i < D; i++) {
        scanf("%d %d", &problems[i].number, &problems[i].bonus);
    }

    // Initialize answer variable ans with a large value
    int ans = 10000;

    // Loop through all possible combinations of problems using binary numbers
    for (int bit = 0; bit < (1 << D); bit++) {
        // Initialize variables score and solved to calculate the score and number of problems solved
        int score = 0;
        int solved = 0;
        // Initialize variable ok to check if the current combination can form a valid solution
        int ok = 0;

        // Loop through each problem in the slice
        for (int j = 0; j < D; j++) {
            // Check if the current bit is set for the problem j
            if (bit & (1 << j)) {
                // If set, add the score and solved count for the problem
                score += (j + 1) * 100 * problems[j].number + problems[j].bonus;
                solved += problems[j].number;
            }
        }

        // Check if the current combination can form a valid solution by checking if the score is greater than or equal to G
        if (score < G) {
            // If not, try to add more problems to the current combination to form a valid solution
            for (int j = D - 1; j >= 0; j--) {
                // Find the last problem that is not included in the current combination
                if (!(bit & (1 << j))) {
                    // Loop through each number of the last problem and check if adding it to the current combination forms a valid solution
                    for (int k = 0; k < problems[j].number; k++) {
                        // Add the score and solved count for the problem
                        score += (j + 1) * 100;
                        solved++;
                        // Check if the current combination can form a valid solution
                        if (score >= G) {
                            // If yes, set ok to true and break the inner loop
                            ok = 1;
                            break;
                        }
                    }
                    // If adding all numbers of the last problem does not form a valid solution, check if adding the bonus of the last problem forms a valid solution
                    if (problems[j].bonus > 0) {
                        // Add the bonus of the last problem to the score and solved count
                        score += problems[j].bonus;
                        solved++;
                        // Check if the current combination can form a valid solution
                        if (score >= G) {
                            // If yes, set ok to true and break the inner loop
                            ok = 1;
                            break;
                        }
                    }
                }
                // If a valid solution is found, break the outer loop
                if (ok) {
                    break;
                }
            }
        } else {
            // If the current combination forms a valid solution, update the answer variable with the minimum solved count
            ok = 1;
        }

        // If the current combination forms a valid solution, update the answer variable
        if (ok) {
            ans = min(ans, solved);
        }
    }

    // Print the answer variable
    printf("%d\n", ans);

    // Free the allocated memory
    free(problems);

    return 0;
}
