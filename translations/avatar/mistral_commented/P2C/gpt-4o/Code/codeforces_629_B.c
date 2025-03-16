#include <stdio.h>

#define N 368

int main() {
    // Initializing the arrays m and f with zeros for all indices up to N
    int m[N] = {0};
    int f[N] = {0};

    // Reading the number of operations
    int operations;
    scanf("%d", &operations);
    
    // Processing each operation
    for (int i = 0; i < operations; i++) {
        char x;
        int a, b;
        // Reading an operation line
        scanf(" %c %d %d", &x, &a, &b);
        b += 1; // Increment b by 1

        // If the operation is 'M', updating the m array accordingly
        if (x == 'M') {
            m[a] += 2;
            m[b] -= 2;
        }
        // If the operation is 'F', updating the f array accordingly
        else {
            f[a] += 2;
            f[b] -= 2;
        }
    }

    // Initializing three variables a, b, and c with zeros
    int a_sum = 0, b_sum = 0, c = 0;

    // Calculating the prefix sums of m and f arrays
    for (int i = 0; i < N; i++) {
        // Updating the variables a_sum and b_sum with the sum of m and f arrays respectively
        a_sum += m[i];
        b_sum += f[i];
        // Finding the minimum of a_sum and b_sum and updating the variable c if the minimum is greater than the current value of c
        if (a_sum < b_sum && a_sum > c) {
            c = a_sum;
        } else if (b_sum < a_sum && b_sum > c) {
            c = b_sum;
        }
    }

    // Printing the result, which is the minimum of the prefix sums of m and f arrays
    printf("%d\n", c);

    return 0;
}

// <END-OF-CODE>
