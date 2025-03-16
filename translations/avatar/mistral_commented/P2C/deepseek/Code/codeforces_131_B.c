#include <stdio.h>
#include <stdlib.h>

#define MAX_N 100000

int main() {
    int n;
    int w[MAX_N];
    int count[2 * MAX_N + 1] = {0};
    int c = 0;

    // Read the number of test cases
    scanf("%d", &n);

    // Read the numbers and count their occurrences
    for (int i = 0; i < n; i++) {
        scanf("%d", &w[i]);
        count[w[i] + MAX_N]++;
    }

    // Iterate through each number 'i' and its occurrences
    for (int i = 0; i <= 2 * MAX_N; i++) {
        if (i - MAX_N == 0) {
            c += count[i] * (count[i] - 1);
        } else if (count[MAX_N - i] > 0) {
            c += count[i] * count[MAX_N - i];
        }
    }

    // Print the result divided by 2
    printf("%d\n", c / 2);

    return 0;
}
