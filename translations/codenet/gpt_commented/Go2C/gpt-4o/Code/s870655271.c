#include <stdio.h>
#include <math.h>

// Function to calculate the maximum value from a variable number of integers
int max(int count, ...) {
    va_list args;
    va_start(args, count);
    int res = va_arg(args, int);
    for (int i = 1; i < count; i++) {
        int value = va_arg(args, int);
        res = fmax(value, res);
    }
    va_end(args);
    return res;
}

// Function to calculate the minimum value from a variable number of integers
int min(int count, ...) {
    va_list args;
    va_start(args, count);
    int res = va_arg(args, int);
    for (int i = 1; i < count; i++) {
        int value = va_arg(args, int);
        res = fmin(value, res);
    }
    va_end(args);
    return res;
}

// Function to calculate x raised to the power of y
int pow_int(int x, int y) {
    return (int)pow(x, y);
}

// Function to return the absolute value of an integer
int abs_int(int x) {
<<<<<<< HEAD
    return abs(x);
}

// Function to return the largest integer less than or equal to x
int floor_int(int x) {
=======
    return (x < 0) ? -x : x;
}

// Function to return the largest integer less than or equal to x
int floor_int(double x) {
>>>>>>> 98c87cb78a (data updated)
    return (int)floor(x);
}

int main() {
    // Declare variables for input dimensions and the answer
    int N, M;
    int ans = 0;

    // Read input values for N and M
    scanf("%d %d", &N, &M);

    // Calculate the number of valid positions based on the dimensions
    if (N == 1 && M == 1) {
        // If both dimensions are 1, there's only one position
        ans += 1;
    } else if (N > 1 && M > 1) {
        // If both dimensions are greater than 1, calculate the inner positions
        ans += (N - 2) * (M - 2);
    } else {
        // If one dimension is 1, count the edge positions
        ans += (N * M) - 2;
    }

    // Output the calculated answer
    printf("%d\n", ans);

    return 0;
}

/* <END-OF-CODE> */
