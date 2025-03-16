
#include <stdio.h>

// Function to read a single line from standard input and strip any trailing whitespace characters.
char* rs() {
    char* str = NULL;
    size_t size = 0;
    getline(&str, &size, stdin);
    return str;
}

// Function to read an integer from standard input.
int ri() {
    char* str = rs();
    int num = atoi(str);
    return num;
}

// Function to read a list of strings from standard input.
char** rs_() {
    char* str = rs();
    char** str_list = (char**)malloc(sizeof(char*) * 1000);
    int i = 0;
    char* token = strtok(str, " ");
    while (token != NULL) {
        str_list[i] = token;
        i++;
        token = strtok(NULL, " ");
    }
    return str_list;
}

// Function to read a list of integers from standard input.
int* ri_() {
    char** str_list = rs_();
    int* num_list = (int*)malloc(sizeof(int) * 1000);
    int i = 0;
    while (str_list[i] != NULL) {
        num_list[i] = atoi(str_list[i]);
        i++;
    }
    return num_list;
}

// Read the integer value of N from standard input.
int N = ri();

// Initialize the variable ans to 0.
int ans = 0;

// Start a loop that iterates from 1 to N + 1.
for (int i = 1; i <= N + 1; i++) {
    // Calculate the sum of multiples of i up to N using the formula for the sum of an arithmetic series.
    ans += i * (N / i) * (N / i + 1) / 2;
}

// Print the final value of ans, which represents the sum of multiples of numbers from 1 to N.
printf("%d\n", ans);

