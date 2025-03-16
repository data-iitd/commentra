#include <stdio.h>
#include <math.h>

long A, N, B; // Global variables to hold the values of A, N, and B

int isValidInput(long n, long a, long b) {
    return (1 <= n && n <= pow(10, 18) && 0 <= a && 0 <= b && 0 < a + b && a + b <= pow(10, 18));
}

long calculateK(long n, long a, long b) {
    return n / (a + b);
}

int remainingPartGreaterThanA(long n, long k, long a) {
    return (n - k * (a + b)) > a;
}

void printResult(long n, long k, long a) {
    long result = 0;
    if (remainingPartGreaterThanA(n, k, a)) {
        result = a * k + (n - k * (a + b)) - (n - (k * (a + b) + a));
    } else {
        result = a * k + (n - k * (a + b));
    }
    printf("%ld\n", result);
}

void printA() {
    printf("%ld\n", A);
}

void printN() {
    printf("%ld\n", N);
}

int main() {
    scanf("%ld", &N); // Reading the first long integer `N`
    scanf("%ld", &A); // Reading the second long integer `A`
    scanf("%ld", &B); // Reading the third long integer `B`

    long k = 0; // Initializing a long variable `k` with the value 0

    if (isValidInput(N, A, B)) { // Checking if the input values are valid
        if (A + B <= N) { // Checking if the sum of `A` and `B` is less than or equal to `N`
            k = calculateK(N, A, B); // Calculating the number of times `A + B` can be added to `N` and storing the result in `k`

            if (remainingPartGreaterThanA(N, k, A)) { // Checking if the remaining part of `N` after subtracting `k * (A + B)` is greater than `A`
                printResult(N, k, A); // Printing the result
            } else {
                printResult(N, k, A); // Printing the result
            }
        } else if (A + B > N && A <= N) { // Checking if the sum of `A` and `B` is greater than `N`, but `A` is less than or equal to `N`
            printA(); // Printing the value of `A`
        } else { // If neither of the above conditions is true
            printN(); // Printing the value of `N`
        }
    }

    return 0; // Return statement for main function
}

// <END-OF-CODE>
