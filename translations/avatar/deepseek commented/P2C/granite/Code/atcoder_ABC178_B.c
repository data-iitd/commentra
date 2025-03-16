
#include <stdio.h>
// Including standard input/output library for input/output operations.

int main() {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    // Reading four integers from standard input using scanf function.
    int ans = a * c;
    ans = ans > b * d? ans : b * d;
    ans = ans > a * d? ans : a * d;
    ans = ans > b * c? ans : b * c;
    // Calculating and storing the maximum of four possible products of two of the given numbers.
    printf("%d\n", ans);
    // Printing the result of the calculation.
    return 0;
}
// End of the C code.