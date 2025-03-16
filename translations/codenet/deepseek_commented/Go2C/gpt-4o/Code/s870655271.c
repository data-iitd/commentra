#include <stdio.h>
#include <math.h>

<<<<<<< HEAD
=======
// This is the main function where the program starts execution.
// It reads two integers N and M from the standard input.
// Depending on the values of N and M, it calculates the number of cells in the grid.
// Finally, it prints the result to the standard output.
int main() {
    int N, M;
    int ans = 0;
    scanf("%d %d", &N, &M);
    
    // If both N and M are 1, there is only one cell, so the answer is 1.
    if (N == 1 && M == 1) {
        ans += 1;
    } else if (N > 1 && M > 1) {
        // If both N and M are greater than 1, the number of cells is (N-2)*(M-2).
        ans += (N - 2) * (M - 2);
    } else {
        // If either N or M is 1, the number of cells is (N*M) - 2.
        ans += (N * M) - 2;
    }

    printf("%d\n", ans);
    return 0;
}

/*  ----------------------------------------  */

>>>>>>> 98c87cb78a (data updated)
// This function returns the maximum value among the given integers.
int max(int count, ...) {
    va_list args;
    va_start(args, count);
    int res = va_arg(args, int);
    for (int i = 1; i < count; i++) {
        int val = va_arg(args, int);
        res = fmax(val, res);
    }
    va_end(args);
    return res;
}

// This function returns the minimum value among the given integers.
int min(int count, ...) {
    va_list args;
    va_start(args, count);
    int res = va_arg(args, int);
    for (int i = 1; i < count; i++) {
        int val = va_arg(args, int);
        res = fmin(val, res);
    }
    va_end(args);
    return res;
}

// This function returns x raised to the power of y.
int pow_int(int x, int y) {
    return (int)pow(x, y);
}

// This function returns the absolute value of x.
int abs_int(int x) {
    return abs(x);
}

// This function returns the floor value of x.
int floor_int(double x) {
    return (int)floor(x);
}

<<<<<<< HEAD
int main() {
    int N, M, ans = 0;
    scanf("%d %d", &N, &M);
    
    // If both N and M are 1, there is only one cell, so the answer is 1.
    if (N == 1 && M == 1) {
        ans += 1;
    } else if (N > 1 && M > 1) {
        // If both N and M are greater than 1, the number of cells is (N-2)*(M-2).
        ans += (N - 2) * (M - 2);
    } else {
        // If either N or M is 1, the number of cells is (N*M) - 2.
        ans += (N * M) - 2;
    }

    printf("%d\n", ans);
    return 0;
}

/*  ----------------------------------------  */

// This type is a structure for sorting integers by their absolute values.
typedef struct {
    int *array;
    int length;
} SortBy;

// Function to compare absolute values for sorting.
int compare_abs(const void *a, const void *b) {
    return abs_int(*(int *)a) - abs_int(*(int *)b);
}

// Function to sort the array by absolute values.
void sort_by_abs(SortBy *sortBy) {
    qsort(sortBy->array, sortBy->length, sizeof(int), compare_abs);
=======
// This function sorts an array of integers by their absolute values.
void sort_by_abs(int *arr, int size) {
    // Simple bubble sort for demonstration purposes
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (abs_int(arr[j]) > abs_int(arr[j + 1])) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
>>>>>>> 98c87cb78a (data updated)
}

// <END-OF-CODE>
