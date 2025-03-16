#include <stdio.h>
#include <stdlib.h>

// Function to read an integer from standard input
int readInt() {
    int num;
    scanf("%d", &num);
    return num;
}

// Function to read a float from standard input
double readFloat() {
    double num;
    scanf("%lf", &num);
    return num;
}

// Function to read a string from standard input
char* readString() {
    char *str = (char*)malloc(100 * sizeof(char));
    scanf("%s", str);
    return str;
}

// Function to read a rune slice from standard input
char* readRuneSlice() {
    char *str = (char*)malloc(100 * sizeof(char));
    scanf("%s", str);
    return str;
}

// Function to read a slice of integers from standard input
int* readIntSlice(int n) {
    int *arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    return arr;
}

// Function to read a slice of floats from standard input
double* readFloatSlice(int n) {
    double *arr = (double*)malloc(n * sizeof(double));
    for (int i = 0; i < n; i++) {
        scanf("%lf", &arr[i]);
    }
    return arr;
}

// Function to find the maximum of three integers
int max(int a, int b, int c) {
    return a > b ? (a > c ? a : c) : (b > c ? b : c);
}

// Function to find the minimum of three integers
int min(int a, int b, int c) {
    return a < b ? (a < c ? a : c) : (b < c ? b : c);
}

// Function to return the absolute value of an integer
int abs(int x) {
    return x > 0 ? x : -x;
}

// Function to calculate x raised to the power of y
int pow(int x, int y) {
    int result = 1;
    for (int i = 0; i < y; i++) {
        result *= x;
    }
    return result;
}

int main() {
    // Read input values
    int A = readInt();
    int B = readInt();
    int C = readInt();
    int K = readInt();

    // Determine the maximum value among A, B, and C
    int ma = max(A, B, C);

    // Calculate the sum of the other two values
    int rest = 0;
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

    // Print the final result
    printf("%d\n", ma + rest);

    return 0;
}
