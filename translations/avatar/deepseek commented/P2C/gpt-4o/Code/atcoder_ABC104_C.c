#include <stdio.h>
#include <limits.h>

int main() {
    int D, G;
    scanf("%d %d", &D, &G);  // Reading the number of problems and target score
    int PC[D][2];  // Array to store the number of problems and bonus points for each problem

    for (int i = 0; i < D; i++) {
        scanf("%d %d", &PC[i][0], &PC[i][1]);  // Reading the number of problems and bonus points
    }

    int ans = INT_MAX;  // Initializing the answer to a large number

    // Iterating over all possible combinations of problems using a bitmask approach
    for (int i = 0; i < (1 << D); i++) {
        int score = 0;  // Initializing the current score
        int problem = 0;  // Initializing the number of problems solved

        // Calculating the total score and the number of problems solved for the current combination
        for (int j = 0; j < D; j++) {
            if ((i >> j) & 1) {
                score += 100 * (j + 1) * PC[j][0] + PC[j][1];
                problem += PC[j][0];
            }
        }

        // If the total score is greater than or equal to the target score, skip to the next combination
        if (score >= G) {
            continue;
        }

        // Calculating the remaining score needed to reach or exceed the target score
        int left = G - score;

        // Checking if the remaining score can be achieved by solving additional problems
        for (int j = 0; j < D; j++) {
            if ((i >> j) & 1) {
                continue;
            }
            if (left > 100 * (j + 1) * PC[j][0] + PC[j][1]) {
                continue;  // If the remaining score is not enough, continue to the next problem
            } else {
                int tmp = (left + (100 * (j + 1)) - 1) / (100 * (j + 1));  // Calculating the number of problems needed
                if (problem + (tmp < PC[j][0] ? tmp : PC[j][0]) < ans) {
                    ans = problem + (tmp < PC[j][0] ? tmp : PC[j][0]);  // Updating the minimum number of problems solved
                }
            }
        }
    }

    // Printing the minimum number of problems solved to achieve the target score
    printf("%d\n", ans);
    return 0;
}

// <END-OF-CODE>
