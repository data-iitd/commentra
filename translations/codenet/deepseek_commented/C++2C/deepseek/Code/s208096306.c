#include <stdio.h>
#include <stdlib.h>

// Include necessary headers: These headers provide essential functionalities
// such as input/output operations.

int gcd(int a, int b) {
    if (a < b) {
        int temp = a;
        a = b;
        b = temp;
    }
    int r;
    while ((r = a % b) > 0) {
        a = b;
        b = r;
    }
    return b;
}

// Define gcd function: This function computes the greatest common divisor
// of two integers using the Euclidean algorithm.

int main() {
    int n;
    scanf("%d", &n);

    // Read the number of integers.

    int ans;
    scanf("%d", &ans);

    // Read the first integer and initialize the answer.

    for (int i = 1; i < n; ++i) {
        int a;
        scanf("%d", &a);
        ans = gcd(ans, a);
    }

    // Read the remaining integers, compute their GCD with the current answer,
    // and update the answer accordingly.

    printf("%d\n", ans);

    // Print the final result, which is the GCD of all the input integers.

    return 0;
}
