#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_STR_LEN 100
#define MAX_PERMUTATIONS 720 // 6! for 3 strings

// Function to check if given indices are valid
int valid(int i, int j, int n, int m) {
    return (i >= 0 && i < n && j >= 0 && j < m);
}

// Function to calculate sum of first n natural numbers
long long sumn(int i, int n) {
    return (long long)(n - i) * (i + n) / 2;
}

// Function to calculate square root of a number using quadratic formula
double sqfun(double a, double b, double c) {
    return (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
}

// Function to read a single integer
int inp() {
    int x;
    scanf("%d", &x);
    return x;
}

// Function to read a single string
void instr(char *str) {
    scanf("%s", str);
}

// Function to generate permutations
void permute(char *str, int l, int r, char permutations[][MAX_STR_LEN], int *count) {
    if (l == r) {
        strcpy(permutations[*count], str);
        (*count)++;
    } else {
        for (int i = l; i <= r; i++) {
            // Swap
            char temp = str[l];
            str[l] = str[i];
            str[i] = temp;

            // Recur
            permute(str, l + 1, r, permutations, count);

            // Backtrack
            temp = str[l];
            str[l] = str[i];
            str[i] = temp;
        }
    }
}

// Main function to solve the problem
void solve() {
    char strings[3][MAX_STR_LEN];
    char permutations[MAX_PERMUTATIONS][MAX_STR_LEN];
    int count = 0;

    // Read three strings
    for (int i = 0; i < 3; i++) {
        instr(strings[i]);
    }

    // Generate all permutations of the three strings
    permute(strings[0], 0, 2, permutations, &count);

    // Read number of test cases
    int test_cases = inp();
    for (int i = 0; i < test_cases; i++) {
        char test_string[MAX_STR_LEN];
        instr(test_string);
        int found = 0;

        // Check if the test string is in the permutations
        for (int j = 0; j < count; j++) {
            if (strcmp(permutations[j], test_string) == 0) {
                found = 1;
                break;
            }
        }

        if (found) {
            printf("ACC\n");
        } else {
            printf("WA\n");
        }
    }
}

// Starting the program
int main() {
    solve();
    return 0;
}

// <END-OF-CODE>
