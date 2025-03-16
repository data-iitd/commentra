#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define INITIAL_BUF_SIZE 10000
#define MAX_BUF_SIZE 1000000
#define MOD 1000000007

char week[7][4] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};

// Function to get a string from standard input.
char* getString() {
    char *buf = (char*)malloc(INITIAL_BUF_SIZE * sizeof(char));
    if (buf == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    if (fgets(buf, INITIAL_BUF_SIZE, stdin) == NULL) {
        fprintf(stderr, "Failed to read input\n");
        exit(1);
    }
    // Remove newline character if present
    buf[strcspn(buf, "\n")] = '\0';
    return buf;
}

// Function to get an integer from standard input.
int getInt() {
    char buf[12]; // Enough to hold the entire input for a 32-bit integer
    if (fgets(buf, 12, stdin) == NULL) {
        fprintf(stderr, "Failed to read input\n");
        exit(1);
    }
    return atoi(buf);
}

// Function to return the absolute value of an integer.
int abs(int a) {
    return abs(a);
}

// Function to return the result of raising the first argument to the power of the second argument.
int pow(int p, int q) {
    return (int)pow((double)p, (double)q);
}

// Function to return the smallest integer from a list of integers.
int min(int nums[], int size) {
    int res = nums[0];
    for (int i = 1; i < size; i++) {
        if (nums[i] < res) {
            res = nums[i];
        }
    }
    return res;
}

// Function to return the largest integer from a list of integers.
int max(int nums[], int size) {
    int res = nums[0];
    for (int i = 1; i < size; i++) {
        if (nums[i] > res) {
            res = nums[i];
        }
    }
    return res;
}

// Function to check if a string is present in a slice of strings.
int strSearch(char* a[], char* b) {
    for (int i = 0; i < 7; i++) {
        if (strcmp(a[i], b) == 0) {
            return 1;
        }
    }
    return 0;
}

// Function to print a slice of integers in a specific format.
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

// Function to return the modulo of an integer with respect to MOD.
int calcMod(int x) {
    return x % MOD;
}

// Main function to determine the number of days until Sunday for a given day.
int main() {
    char* s = getString(); // Get the input day as a string.
    int index = -1;
    for (int i = 0; i < 7; i++) {
        if (strcmp(s, week[i]) == 0) {
            index = i; // Set the index of the day found in the week array.
            break;
        }
    }

    printf("%d\n", 7 - index); // Print the number of days until Sunday.

    return 0;
}
