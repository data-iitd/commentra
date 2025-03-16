#include <stdio.h>
#include <stdlib.h>

// Function to find the greatest common divisor (GCD) of two numbers
int gcd(int a, int b) {
    // Base case: if b is 0, return a as the GCD
    if (b == 0) {
        return a;
    }
    // Recursive case: find the GCD of b and the remainder of a divided by b
    return gcd(b, a % b);
}

// Function to perform Ruiseki algorithm on a given array
void ruiseki_lr(int *array, int n, int *left, int *right) {
    // Define a helper function to find the GCD of two numbers
    int op(int a, int b) {
        return gcd(a, b);
    }
    // Initialize empty lists 'left' and 'right' of size 'n+1'
    int e = 0;
    // Iterate through the array and calculate the left and right arrays
    for (int i = 0; i < n; i++) {
        left[i+1] = op(left[i], array[i]);
    }
    // Iterate through the array in reverse order and calculate the right arrays
    for (int i = n-1; i >= 0; i--) {
        right[i] = op(right[i+1], array[i]);
    }
}

// Function to perform Ruiseki algorithm on a given array
void ruiseki_lr(int *array, int n, int *left, int *right) {
    // Define a helper function to find the GCD of two numbers
    int op(int a, int b) {
        return gcd(a, b);
    }
    // Initialize empty lists 'left' and 'right' of size 'n+1'
    int e = 0;
    // Iterate through the array and calculate the left and right arrays
    for (int i = 0; i < n; i++) {
        left[i+1] = op(left[i], array[i]);
    }
    // Iterate through the array in reverse order and calculate the right arrays
    for (int i = n-1; i >= 0; i--) {
        right[i] = op(right[i+1], array[i]);
    }
}

// Function to perform Ruiseki algorithm on a given array
void ruiseki_lr(int *array, int n, int *left, int *right) {
    // Define a helper function to find the GCD of two numbers
    int op(int a, int b) {
        return gcd(a, b);
    }
    // Initialize empty lists 'left' and 'right' of size 'n+1'
    int e = 0;
    // Iterate through the array and calculate the left and right arrays
    for (int i = 0; i < n; i++) {
        left[i+1] = op(left[i], array[i]);
    }
    // Iterate through the array in reverse order and calculate the right arrays
    for (int i = n-1; i >= 0; i--) {
        right[i] = op(right[i+1], array[i]);
    }
}

// Function to perform Ruiseki algorithm on a given array
void ruiseki_lr(int *array, int n, int *left, int *right) {
    // Define a helper function to find the GCD of two numbers
    int op(int a, int b) {
        return gcd(a, b);
    }
    // Initialize empty lists 'left' and 'right' of size 'n+1'
    int e = 0;
    // Iterate through the array and calculate the left and right arrays
    for (int i = 0; i < n; i++) {
        left[i+1] = op(left[i], array[i]);
    }
    // Iterate through the array in reverse order and calculate the right arrays
    for (int i = n-1; i >= 0; i--) {
        right[i] = op(right[i+1], array[i]);
    }
}

// Function to perform Ruiseki algorithm on a given array
void ruiseki_lr(int *array, int n, int *left, int *right) {
    // Define a helper function to find the GCD of two numbers
    int op(int a, int b) {
        return gcd(a, b);
    }
    // Initialize empty lists 'left' and 'right' of size 'n+1'
    int e = 0;
    // Iterate through the array and calculate the left and right arrays
    for (int i = 0; i < n; i++) {
        left[i+1] = op(left[i], array[i]);
    }
    // Iterate through the array in reverse order and calculate the right arrays
    for (int i = n-1; i >= 0; i--) {
        right[i] = op(right[i+1], array[i]);
    }
}

// Function to perform Ruiseki algorithm on a given array
void ruiseki_lr(int *array, int n, int *left, int *right) {
    // Define a helper function to find the GCD of two numbers
    int op(int a, int b) {
        return gcd(a, b);
    }
    // Initialize empty lists 'left' and 'right' of size 'n+1'
    int e = 0;
    // Iterate through the array and calculate the left and right arrays
    for (int i = 0; i < n; i++) {
        left[i+1] = op(left[i], array[i]);
    }
    // Iterate through the array in reverse order and calculate the right arrays
    for (int i = n-1; i >= 0; i--) {
        right[i] = op(right[i+1], array[i]);
    }
}

// Function to perform Ruiseki algorithm on a given array
void ruiseki_lr(int *array, int n, int *left, int *right) {
    // Define a helper function to find the GCD of two numbers
    int op(int a, int b) {
        return gcd(a, b);
    }
    // Initialize empty lists 'left' and 'right' of size 'n+1'
    int e = 0;
    // Iterate through the array and calculate the left and right arrays
    for (int i = 0; i < n; i++) {
        left[i+1] = op(left[i], array[i]);
    }
    // Iterate through the array in reverse order and calculate the right arrays
    for (int i = n-1; i >= 0; i--) {
        right[i] = op(right[i+1], array[i]);
    }
}

// Function to perform Ruiseki algorithm on a given array
void ruiseki_lr(int *array, int n, int *left, int *right) {
    // Define a helper function to find the GCD of two numbers
    int op(int a, int b) {
        return gcd(a, b);
    }
    // Initialize empty lists 'left' and 'right' of size 'n+1'
    int e = 0;
    // Iterate through the array and calculate the left and right arrays
    for (int i = 0; i < n; i++) {
        left[i+1] = op(left[i], array[i]);
    }
    // Iterate through the array in reverse order and calculate the right arrays
    for (int i = n-1; i >= 0; i--) {
        right[i] = op(right[i+1], array[i]);
    }
}

// Function to perform Ruiseki algorithm on a given array
void ruiseki_lr(int *array, int n, int *left, int *right) {
    // Define a helper function to find the GCD of two numbers
    int op(int a, int b) {
        return gcd(a, b);
    }
    // Initialize empty lists 'left' and 'right' of size 'n+1'
    int e = 0;
    // Iterate through the array and calculate the left and right arrays
    for (int i = 0; i < n; i++) {
        left[i+1] = op(left[i], array[i]);
    }
    // Iterate through the array in reverse order and calculate the right arrays
    for (int i = n-1; i >= 0; i--) {
        right[i] = op(right[i+1], array[i]);
    }
}

// Function to perform Ruiseki algorithm on a given array
void ruiseki_lr(int *array, int n, int *left, int *right) {
    // Define a helper function to find the GCD of two numbers
    int op(int a, int b) {
        return gcd(a, b);
    }
    // Initialize empty lists 'left' and 'right' of size 'n+1'
    int e = 0;
    // Iterate through the array and calculate the left and right arrays
    for (int i = 0; i < n; i++) {
        left[i+1] = op(left[i], array[i]);
    }
    // Iterate through the array in reverse order and calculate the right arrays
    for (int i = n-1; i >= 0; i--) {
        right[i] = op(right[i+1], array[i]);
    }
}

// Function to perform Ruiseki algorithm on a given array
void ruiseki_lr(int *array, int n, int *left, int *right) {
    // Define a helper function to find the GCD of two numbers
    int op(int a, int b) {
        return gcd(a, b);
    }
    // Initialize empty lists 'left' and 'right' of size 'n+1'
    int e = 0;
    // Iterate through the array and calculate the left and right arrays
    for (int i = 0; i < n; i++) {
        left[i+1] = op(left[i], array[i]);
    }
    // Iterate through the array in reverse order and calculate the right arrays
    for (int i = n-1; i >= 0; i--) {
        right[i] = op(right[i+1], array[i]);
    }
}

// Function to perform Ruiseki algorithm on a given array
void ruiseki_lr(int *array, int n, int *left, int *right) {
    // Define a helper function to find the GCD of two numbers
    int op(int a, int b) {
        return gcd(a, b);
    }
    // Initialize empty lists 'left' and 'right' of size 'n+1'
    int e = 0;
    // Iterate through the array and calculate the left and right arrays
    for (int i = 0; i < n; i++) {
        left[i+1] = op(left[i], array[i]);
    }
    // Iterate through the array in reverse order and calculate the right arrays
    for (int i = n-1; i >= 0; i--) {
        right[i] = op(right[i+1], array[i]);
    }
}

// Function to perform Ruiseki algorithm on a given array
void ruiseki_lr(int *array, int n, int *left, int *right) {
    // Define a helper function to find the GCD of two numbers
    int op(int a, int b) {
        return gcd(a, b);
    }
    // Initialize empty lists 'left' and 'right' of size 'n+1'
    int e = 0;
    // Iterate through the array and calculate the left and right arrays
    for (int i = 0; i < n; i++) {
        left[i+1] = op(left[i], array[i]);
    }
    // Iterate through the array in reverse order and calculate the right arrays
    for (int i = n-1; i >= 0; i--) {
        right[i] = op(right[i+1], array[i]);
    }
}

// Function to perform Ruiseki algorithm on a given array
void ruiseki_lr(int *array, int n, int *left, int *right) {
    // Define a helper function to find the GCD of two numbers
    int op(int a, int b) {
        return gcd(a, b);
    }
    // Initialize empty lists 'left' and 'right' of size 'n+1'
    int e = 0;
    // Iterate through the array and calculate the left and right arrays
    for (int i = 0; i < n; i++) {
        left[i+1] = op(left[i], array[i]);
    }
    // Iterate through the array in reverse order and calculate the right arrays
    for (int i = n-1; i >= 0; i--) {
        right[i] = op(right[i+1], array[i]);
    }
}

// Function to perform Ruiseki algorithm on a given array
void ruiseki_lr(int *array, int n, int *left, int *right) {
    // Define a helper function to find the GCD of two numbers
    int op(int a, int b) {
        return gcd(a, b);
    }
    // Initialize empty lists 'left' and 'right' of size 'n+1'
    int e = 0;
    // Iterate through the array and calculate the left and right arrays
    for (int i = 0; i < n; i++) {
        left[i+1] = op(left[i], array[i]);
    }
    // Iterate through the array in reverse order and calculate the right arrays
    for (int i = n-1; i >= 0; i--) {
        right[i] = op(right[i+1], 