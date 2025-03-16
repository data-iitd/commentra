
#include <stdio.h>

int main() {
    // Initializing the arrays m and f with zeros for all indices up to N
    int N = 368;
    int m[N] = {0};
    int f[N] = {0};

    // Reading the number of operations from the standard input and processing each operation
    for (int i = 0; i < int(input()); i++) {
        // Reading an operation line and splitting it into components
        char x[2];
        int a, b;
        scanf("%s %d %d", x, &a, &b);
        // Incrementing or decrementing the corresponding array based on the operation type
        if (x[0] == 'M') {
            m[a] += 2;
            m[b + 1] -= 2;
        } else {
            f[a] += 2;
            f[b + 1] -= 2;
        }
    }

    // Initializing three variables a, b, and c with zeros
    int a = 0, b = 0, c = 0;

    // Calculating the prefix sums of m and f arrays
    for (int i = 0; i < N; i++) {
        // Updating the variables a and b with the sum of m and f arrays respectively
        a += m[i];
        b += f[i];
        // Finding the minimum of a and b and updating the variable c if the minimum is greater than the current value of c
        if (a < b) {
            if (a > c) {
                c = a;
            }
        } else {
            if (b > c) {
                c = b;
            }
        }
    }

    // Printing the result, which is the minimum of the prefix sums of m and f arrays
    printf("%d\n", c);

    return 0;
}
