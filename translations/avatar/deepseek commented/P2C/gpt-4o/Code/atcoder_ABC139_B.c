#include <stdio.h>

int main() {
    int a, b;
    // Taking two integer inputs, `a` and `b`.
    scanf("%d %d", &a, &b);
    
    int hole = 1;
    int i = 0;
    // Initializing `hole` to 1 and `i` to 0.
    int check = 1; // Using 1 for true

    // The `while` loop runs as long as `check` is `True`.
    while (check) {
        // Checking if `hole` is greater than or equal to `b`.
        if (hole >= b) {
            check = 0; // If so, set `check` to `False` to exit the loop.
        } else {
            hole = a * (i + 1) - i;
            // If `hole` is less than `b`, update `hole` to `a * (i + 1) - i`.
            i += 1;
            // Increment `i` by 1.
        }
    }
    printf("%d\n", i);
    // Finally, print the value of `i` after the loop exits.

    return 0;
}
// <END-OF-CODE>
