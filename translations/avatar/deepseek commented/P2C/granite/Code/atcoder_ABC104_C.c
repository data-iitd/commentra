
#include <stdio.h>
#include <limits.h>

int main() {
    int D, G;
    scanf("%d %d", &D, &G);  // Reading the number of problems and target score
    int PC[D][2];  // Array to store the number of problems and bonus points for each problem
    for (int i = 0; i < D; i++) {
        scanf("%d %d", &PC[i][0], &PC[i][1]);  // Reading the number of problems and bonus points for each problem
    }
    int ans = INT_MAX;  // Initializing the answer to the maximum integer value
    for (int i = 0; i < (1 << D); i++) {
        int score = 0;  // Initializing the current score
        int problem = 0;  // Initializing the number of problems solved
        for (int j = 0; j < D; j++) {
            if ((i >> j) & 1) {
                score += 100 * (j + 1) * PC[j][0] + PC[j][1];
                problem += PC[j][0];
            }
        }
        if (score >= G) {
            continue;  // If the total score is greater than or equal to the target score, skip to the next combination
        }
        int left = G - score;  // Calculating the remaining score needed to reach or exceed the target score
        for (int j = 0; j < D; j++) {
            if ((i >> j) & 1) {
                continue;  // If the current problem has already been solved, skip to the next problem
            }
            if (left > 100 * (j + 1) * PC[j][0] + PC[j][1]) {
                continue;  // If the remaining score is not enough, continue to the next problem
            }
            int tmp = (left + (100 * (j + 1)) - 1) / (100 * (j + 1));  // Calculating the number of problems needed
            ans = ans < problem + tmp? ans : problem + tmp;  // Updating the minimum number of problems solved
        }
    }
    printf("%d\n", ans);  // Printing the minimum number of problems solved to achieve the target score
    return 0;
}
