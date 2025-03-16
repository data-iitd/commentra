#include <stdio.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    // Taking two integer inputs, `n` and `m`

    int i = 1;
    // Initializing `i` to 1

    while (m >= i) {
        // The loop continues as long as `m` is greater than or equal to `i`
        m -= i;
        // Subtracting `i` from `m`
        i = (i % n) + 1;
        // Updating `i` to be `(i % n) + 1`
    }

    printf("%d\n", m);
    // Printing the value of `m` after the loop completes

    return 0;
}
// <END-OF-CODE>
