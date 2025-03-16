
#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);
    // Ask the user for an integer `N` and store it in a variable called `N`

    int A[N];
    for (int i = 0; i < N; i++) {
        int a;
        scanf("%d", &a);
        // Ask the user for an integer `a` and store it in the `i`-th element of the array `A`.

        A[i] = a * N + i;
        // Calculate the value of `A[i]` as the product of `a` and `N`, plus `i`.
    }

    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (A[i] > A[j]) {
                // Swap the values of `A[i]` and `A[j]` if `A[i]` is greater than `A[j]`.
            }
        }
    }

    int cnt = 0;
    for (int i = 0; i < N; i++) {
        int d = (A[i] % N) % 2;
        // Calculate the remainder of `A[i]` divided by `N` and modulo 2.
        // Store this result in a variable called `d`.

        if (d % 2!= i % 2) {
            // Check if the remainder of `d` divided by 2 is different from the remainder of `i` divided by 2.
            // If they are different, increment the counter `cnt` by 1.
            cnt++;
        }
    }

    printf("%d\n", cnt / 2);
    // After the loop finishes, print the result of the counter `cnt` divided by 2.

    return 0;
}
