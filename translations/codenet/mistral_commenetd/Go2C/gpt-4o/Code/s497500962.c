#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to read the next integer from standard input
int nextInt() {
    int value;
    scanf("%d", &value);
    return value;
}

int main() {
    // Initialize variables R, G, B, and N with next integers
    int R = nextInt();
    int G = nextInt();
    int B = nextInt();
    int N = nextInt();

    // Initialize variable ans with zero
    int ans = 0;

    // Nested for loops to iterate through all possible combinations of x and y within the range of N
    for (int x = 0; x <= N; x++) {
        for (int y = 0; y <= N; y++) {
            // Calculate temporary variable tmp
            int tmp = N - R * x - G * y;

            // Check if tmp is non-negative and the remainder of tmp when divided by B is zero
            if (tmp >= 0 && tmp % B == 0) {
                // Increment the value of ans if the condition is true
                ans++;
            }
        }
    }

    // Print the value of ans
    printf("%d\n", ans);

    return 0;
}

// Utility functions (not needed in this case, but included for completeness)
int abs(int x) {
    return x < 0 ? -x : x;
}

int min(int x, int y) {
    return x < y ? x : y;
}

int max(int x, int y) {
    return x > y ? x : y;
}

// <END-OF-CODE>
