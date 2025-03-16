#include <stdio.h>
#include <stdlib.h>

// Function to read the next integer from input
int readInt() {
    int num;
    scanf("%d", &num);
    return num;
}

// Function to read the next float from input
double readFloat() {
    double num;
    scanf("%lf", &num);
    return num;
}

// Function to read the next string from input
void readString(char *str, int size) {
    scanf("%s", str);
}

// Function to read n integers from input and return them as an array
int* readIntArray(int n) {
    int *arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    return arr;
}

// Function to read n floats from input and return them as an array
double* readFloatArray(int n) {
    double *arr = (double*)malloc(n * sizeof(double));
    for (int i = 0; i < n; i++) {
        scanf("%lf", &arr[i]);
    }
    return arr;
}

// Function to find the maximum value among a list of integers
int max(int nums[], int size) {
    int m = nums[0];
    for (int i = 1; i < size; i++) {
        if (m < nums[i]) {
            m = nums[i];
        }
    }
    return m;
}

// Function to find the minimum value among a list of integers
int min(int nums[], int size) {
    int m = nums[0];
    for (int i = 1; i < size; i++) {
        if (m > nums[i]) {
            m = nums[i];
        }
    }
    return m;
}

// Function to return the absolute value of an integer
int abs(int x) {
    if (x > 0) {
        return x;
    }
    return -x;
}

// Function to compute x raised to the power of y
int pow(int x, int y) {
    int res = 1;
    for (int i = 0; i < y; i++) {
        res *= x;
    }
    return res;
}

// Main function
int main() {
    // Read four integers from input
    int A = readInt();
    int B = readInt();
    int C = readInt();
    int K = readInt();

    // Determine the maximum value among A, B, and C
    int ma = max((int[]){A, B, C}, 3);
    int rest = 0; // Initialize the rest variable to hold the sum of the other two values

    // Calculate the sum of the two smaller values
    if (ma == A) {
        rest += B + C;
    } else if (ma == B) {
        rest += A + C;
    } else {
        rest += A + B;
    }

    // Double the maximum value K times
    for (int i = 1; i <= K; i++) {
        ma *= 2;
    }

    // Output the final result: doubled max value plus the sum of the other two
    printf("%d\n", ma + rest);

    return 0;
}
