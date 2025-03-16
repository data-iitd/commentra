#include <stdio.h>  // Including standard input-output library
#include <stdlib.h> // Including standard library for memory allocation and conversion
#include <math.h>   // Including math library for mathematical functions

int main() {
    int n; // Variable to store the number of test cases
    scanf("%d", &n); // Reading the number of test cases

    double arr[2 * n]; // Array to store the elements
    int non_int = 0; // Variable to count non-integer values
    double sum_before = 0, sum = 0; // Variables to store sums

    // Iterating through the array elements and performing the required operations
    for (int i = 0; i < 2 * n; i++) {
        double num;
        scanf("%lf", &num); // Reading the current number
        sum_before += num; // Adding the current number to sum_before
        if (num != floor(num)) non_int++; // Incrementing non_int if the current number is not an integer
        sum += floor(num); // Adding the floor value of the current number to sum
        arr[i] = num; // Assigning the current number to the corresponding index of the array
    }

    // Calculating the maximum and minimum sums
    double max_sum = fmin(n, non_int) + sum; // Maximum sum calculation
    double min_sum = fmax(0, non_int - n) + sum; // Minimum sum calculation

    // Calculating the answer based on the given conditions
    double ans;
    if (min_sum > sum_before) {
        ans = min_sum - sum_before; // Case where min_sum is greater than sum_before
    } else if (max_sum < sum_before) {
        ans = sum_before - max_sum; // Case where max_sum is less than sum_before
    } else {
        double x = sum_before - floor(sum_before); // Fractional part of sum_before
        ans = fmin(1 - x, x); // Minimum of the two possible adjustments
    }

    // Printing the answer
    printf("%.3f\n", ans); // Outputting the result with three decimal places

    return 0; // Indicating successful completion of the program
}

// <END-OF-CODE>
