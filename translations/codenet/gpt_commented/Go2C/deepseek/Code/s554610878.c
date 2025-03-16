#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define INITIAL_BUF_SIZE 10000
#define MAX_BUF_SIZE 1000000
#define MOD 1000000007

// Global variables for scanner and modulus
char buffer[INITIAL_BUF_SIZE];
int bufferIndex = 0;
int bufferSize = 0;

// Function prototypes
int getInt();
char getChar();
char* getString();
int abs(int a);
int pow(int p, int q);
int min(int nums[], int size);
int max(int nums[], int size);
int strSearch(char* a[], int size, char* b);
void printIntArray(int array[], int size);
int calcMod(int x);

// Function to read a single character from input
char getChar() {
    if (bufferIndex >= bufferSize) {
        bufferSize = fread(buffer, 1, INITIAL_BUF_SIZE, stdin);
        bufferIndex = 0;
    }
    return buffer[bufferIndex++];
}

// Function to read an integer from input
int getInt() {
    int num = 0;
    char ch;
    while ((ch = getChar()) >= '0' && ch <= '9') {
        num = num * 10 + (ch - '0');
    }
    return num;
}

// Function to read a string from input
char* getString() {
    char ch;
    int index = 0;
    char* str = (char*)malloc(1000 * sizeof(char)); // Allocate memory for the string
    while ((ch = getChar()) != '\n' && ch != ' ') {
        str[index++] = ch;
    }
    str[index] = '\0'; // Null-terminate the string
    return str;
}

// Function to compute the absolute value of an integer
int abs(int a) {
    return (a < 0) ? -a : a;
}

// Function to compute p raised to the power of q
int pow(int p, int q) {
    int result = 1;
    for (int i = 0; i < q; i++) {
        result *= p;
    }
    return result;
}

// Function to find the minimum value among given integers
int min(int nums[], int size) {
    int res = nums[0];
    for (int i = 1; i < size; i++) {
        if (nums[i] < res) {
            res = nums[i];
        }
    }
    return res;
}

// Function to find the maximum value among given integers
int max(int nums[], int size) {
    int res = nums[0];
    for (int i = 1; i < size; i++) {
        if (nums[i] > res) {
            res = nums[i];
        }
    }
    return res;
}

// Function to check if a string exists in a slice of strings
int strSearch(char* a[], int size, char* b) {
    for (int i = 0; i < size; i++) {
        if (strcmp(a[i], b) == 0) {
            return 1; // Return 1 if the string is found
        }
    }
    return 0; // Return 0 if the string is not found
}

// Function to print an array of integers
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

// Function to calculate the modulus of x with respect to the defined mod
int calcMod(int x) {
    return x % MOD;
}

int main() {
    // Array representing the days of the week
    char* week[] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
    int weekSize = 7;

    // Get the input day as a string
    char* s = getString();
    int index = -1; // Initialize index to -1 to indicate not found

    // Search for the input day in the week array
    for (int i = 0; i < weekSize; i++) {
        if (strcmp(s, week[i]) == 0) {
            index = i; // Update index if the day is found
            break;
        }
    }

    // Calculate and print the number of days until the next Sunday
    printf("%d\n", 7 - index);

    // Free allocated memory for the input string
    free(s);

    return 0;
}
