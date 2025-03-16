#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Function to read a line of input
char* input() {
    char* line = NULL;
    size_t size = 0;
    getline(&line, &size, stdin);
    return line;
}

// Function to compute the ceiling of a divided by b
int ceil(int a, int b) {
    return -((-a) / b);
}

// Function to round a number to the nearest integer
int round(float x) {
    return (x * 2 + 1) / 2;
}

// Function to compute Fermat's little theorem for modular inverse
int fermat(int x, int y, int MOD) {
    return x * pow(y, MOD - 2, MOD) % MOD;
}

// Function to compute the least common multiple of two numbers
int lcm(int x, int y) {
    return (x * y) / gcd(x, y);
}

// Function to compute the least common multiple of a list of numbers
int lcm_list(int* nums, int size) {
    int result = 1;
    for (int i = 0; i < size; i++) {
        result = lcm(result, nums[i]);
    }
    return result;
}

// Function to read an integer from input
int INT() {
    return atoi(input());
}

// Function to read a list of integers from input
int* MAP() {
    char* line = input();
    int* nums = malloc(sizeof(int) * (strlen(line) + 1));
    int size = 0;
    char* token = strtok(line, " ");
    while (token != NULL) {
        nums[size++] = atoi(token);
        token = strtok(NULL, " ");
    }
    return nums;
}

// Function to read a list of integers into a list
int* LIST() {
    char* line = input();
    int* nums = malloc(sizeof(int) * (strlen(line) + 1));
    int size = 0;
    char* token = strtok(line, " ");
    while (token != NULL) {
        nums[size++] = atoi(token);
        token = strtok(NULL, " ");
    }
    return nums;
}

// Set the maximum recursion limit
#define MAX_RECURSION_DEPTH 1000000000

// Define constants for infinity and modulo
#define INF 1000000000
#define MOD 1000000007

int main() {
    // Read input values for costs of different types of drinks
    int q = INT();
    int h = INT();
    int s = INT();
    int d = INT();

    // Read the number of drinks to be purchased
    int n = INT();

    // Calculate the best price for 1 liter of drink
    int best1L = min(q * 4, h * 2, s);

    // Calculate the best price for 2 liters of drink
    int best2L = min(d, best1L * 2);

    // Calculate and print the total cost based on whether n is even or odd
    if (n % 2 == 0) {
        printf("%d\n", best2L * (n / 2));  // Total cost for even number of drinks
    } else {
        printf("%d\n", best2L * (n / 2) + best1L);  // Total cost for odd number of drinks
    }

    return 0;
}

