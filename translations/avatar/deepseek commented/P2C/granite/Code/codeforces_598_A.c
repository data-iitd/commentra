

#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);  // Read the number of test cases

    int solve(int n) {
        int s = (1 + n) * n / 2;
        int t = 1;
        while (t <= n) {
            s -= 2 * t;
            t *= 2;
        }
        return s;
    }

    // Main loop to iterate over the number of test cases
    for (int i = 0; i < t; i++) {
        int n;
        scanf("%d", &n);  // Read each n for the test case
        printf("%d\n", solve(n));  // Print the result of the solve function for the current n
    }

    return 0;
}
