#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define MOD 1000000007
#define INITIAL_BUF_SIZE 10000
#define MAX_BUF_SIZE 1000000

// Function to read an integer from input
int getInt() {
    int i;
    scanf("%d", &i);
    return i;
}

// Function to read a string from input
char* getString() {
    char *buf = (char*)malloc(INITIAL_BUF_SIZE * sizeof(char));
    scanf("%s", buf);
    return buf;
}

// Function to return the absolute value of an integer
int abs(int a) {
    return abs(a);
}

// Function to compute p raised to the power of q
int pow(int p, int q) {
    return (int)pow((double)p, (double)q);
}

// Function to compute (n^p) % mod using exponentiation by squaring
int powMod(int n, int p) {
    if (p == 0) {
        return 1;
    } else if (p % 2 == 0) {
        int t = powMod(n, p / 2);
        return (t * t) % MOD;
    } else {
        return (n * powMod(n, p - 1)) % MOD;
    }
}

// Function to find the minimum value among a variable number of integers
int min(int nums[], int size) {
    int res = nums[0];
    for (int i = 0; i < size; i++) {
        res = fmin(res, nums[i]);
    }
    return res;
}

// Function to find the maximum value among a variable number of integers
int max(int nums[], int size) {
    int res = nums[0];
    for (int i = 0; i < size; i++) {
        res = fmax(res, nums[i]);
    }
    return res;
}

// Function to check if a string exists in a slice of strings
int strSearch(char* a[], int size, char* b) {
    for (int i = 0; i < size; i++) {
        if (strcmp(a[i], b) == 0) {
            return 1;
        }
    }
    return 0;
}

// Function to print an integer array in a formatted way
void printIntArray(int array[], int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d", array[i]);
        if (i < size - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

// Function to calculate x % mod
int calcMod(int x) {
    return x % MOD;
}

// Function to reverse a string
char* reverse(char* s) {
    int len = strlen(s);
    for (int i = 0; i < len / 2; i++) {
        char temp = s[i];
        s[i] = s[len - i - 1];
        s[len - i - 1] = temp;
    }
    return s;
}

// Function to check if a number is prime
int isPrime(int n) {
    if (n < 2) {
        return 0;
    } else if (n == 2) {
        return 1;
    } else if (n % 2 == 0) {
        return 0;
    }

    // Check for factors from 3 to the square root of n
    int sqrtN = (int)sqrt(n);
    for (int i = 3; i <= sqrtN; i += 2) {
        if (n % i == 0) {
            return 0;
        }
    }

    return 1;
}

// Main function
int main() {
    // Read an integer N from input
    int N = getInt();
    // Calculate the integer square root of N
    int sqrtN = (int)sqrt(N);

    // Initialize min to N, which will hold the minimum value found
    int min = N;
    // Iterate through all possible divisors of N
    for (int i = 1; i <= sqrtN; i++) {
        // If i is not a divisor of N, skip to the next iteration
        if (N % i != 0) {
            continue;
        }

        // Calculate the value based on the divisor and its complement
        int num = i + (N / i) - 2;
        // Update min if the new value is smaller
        if (num < min) {
            min = num;
        }
    }

    // Print the minimum value found
    printf("%d\n", min);

    return 0;
}
