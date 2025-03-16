#include <stdio.h>
#include <stdlib.h>

#define N 368

int main() {
    int m[N], f[N];
    int i, a = 0, b = 0, c = 0;
    char x;
    int A, B;
    int num_operations;

    // Initialize the arrays
    for (i = 0; i < N; i++) {
        m[i] = 0;
        f[i] = 0;
    }

    // Read the number of operations
    scanf("%d", &num_operations);
    getchar();  // Consume the newline character after the number

    // Read and process each operation
    for (i = 0; i < num_operations; i++) {
        scanf("%c %d %d", &x, &A, &B);
        getchar();  // Consume the newline character after the operation details

        // Adjust the range for the second index
        B++;

        // Update the corresponding array based on the operation type
        if (x == 'M') {
            m[A] += 2;
            m[B] -= 2;
        } else {
            f[A] += 2;
            f[B] -= 2;
        }
    }

    // Calculate cumulative sums and find the minimum
    for (i = 0; i < N; i++) {
        a += m[i];
        b += f[i];

        // Update the minimum value if the current minimum of a and b is greater than c
        if (a < b && a > c) {
            c = a;
        } else if (b < a && b > c) {
            c = b;
        }
    }

    // Print the final minimum value found
    printf("%d\n", c);

    return 0;
}
