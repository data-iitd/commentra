
#include <stdio.h>
#include <math.h>

// Constants for buffer sizes
#define initialBufSize 10000
#define maxBufSize 1000000

// Global variables for scanner and modulus
static char buf[maxBufSize];
static int bufPos = 0, bufSize = 0;
static int mod = 1e9 + 7; // Modulus value for calculations

// Function to read an integer from input
int getInt() {
    int i;
    scanf("%d", &i);
    return i;
}

// Function to read a string from input
char* getString() {
    scanf("%s", buf);
    return buf;
}

// Function to compute the absolute value of an integer
int abs(int a) {
    return (a < 0)? -a : a;
}

// Function to compute p raised to the power of q
int pow(int p, int q) {
    int res = 1;
    while (q > 0) {
        if (q & 1) {
            res = (res * p) % mod;
        }
        p = (p * p) % mod;
        q >>= 1;
    }
    return res;
}

// Function to find the minimum value among given integers
int min(int n,...) {
    va_list args;
    int res = va_arg(args, int);
    for (int i = 1; i < n; i++) {
        res = (res < va_arg(args, int))? res : va_arg(args, int);
    }
    return res;
}

// Function to find the maximum value among given integers
int max(int n,...) {
    va_list args;
    int res = va_arg(args, int);
    for (int i = 1; i < n; i++) {
        res = (res > va_arg(args, int))? res : va_arg(args, int);
    }
    return res;
}

// Function to check if a string exists in a slice of strings
int strSearch(char** a, int n, char* b) {
    for (int i = 0; i < n; i++) {
        if (strcmp(a[i], b) == 0) {
            return 1; // Return true if the string is found
        }
    }
    return 0; // Return false if the string is not found
}

// Function to print an array of integers
void printIntArray(int* array, int n) {
    printf("[");
    for (int i = 0; i < n; i++) {
        printf("%d", array[i]);
        if (i < n - 1) {
            printf(", ");
        }
    }
    printf("]");
}

// Function to calculate the modulus of x with respect to the defined mod
int calcMod(int x) {
    return x % mod;
}

int main() {
    // Array representing the days of the week
    char* week[] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
    
    // Get the input day as a string
    char* s = getString();
    int index = -1; // Initialize index to -1 to indicate not found
    
    // Search for the input day in the week array
    for (int i = 0; i < 7; i++) {
        if (strcmp(s, week[i]) == 0) {
            index = i; // Update index if the day is found
            break;
        }
    }
    
    // Calculate and print the number of days until the next Sunday
    printf("%d\n", 7 - index);
    
    return 0;
}

// END-OF-CODE