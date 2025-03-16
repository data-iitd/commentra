#include <stdio.h>

int main() {
    int n;
    long ans = 0;

    // Read an integer n from the user
    scanf("%d", &n);

    // Loop from 1 to n (inclusive)
    for (int i = 1; i < n + 1; i++) {
        // Calculate a value based on the current value of i and the variable n
        long term = (long) n / (long) i;
        long sum = term * (term + 1) / 2;
        ans += (long) i * sum;
    }

    // Print the value of ans
    printf("%ld\n", ans);

    return 0;
}
