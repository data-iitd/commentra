#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to read input from standard input
char* input() {
    int size = 1000;
    char* str = (char*)malloc(size * sizeof(char));
    fgets(str, size, stdin);
    return str;
}

// Function to count occurrences of numbers
int count(char* str) {
    int count = 0;
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] == ' ') {
            i++;
            continue;
        }
        count++;
        while (str[i] != ' ' && str[i] != '\0') {
            i++;
        }
    }
    return count;
}

// Function to store the occurrences of numbers
int* store(char* str) {
    int* arr = (int*)malloc(count(str) * sizeof(int));
    int i = 0;
    int j = 0;
    while (str[i] != '\0') {
        if (str[i] == ' ') {
            i++;
            continue;
        }
        arr[j] = atoi(&str[i]);
        while (str[i] != ' ' && str[i] != '\0') {
            i++;
        }
        j++;
    }
    return arr;
}

// Function to find the result
int find(int* arr, int n) {
    int c = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == 0) {
            c += arr[i] * (arr[i] - 1);
        } else if (arr[i] > 0) {
            for (int j = 0; j < n; j++) {
                if (arr[j] == -arr[i]) {
                    c += arr[i] * arr[j];
                }
            }
        }
    }
    return c;
}

// Main function
int main() {
    // Read the number of test cases
    int n = atoi(input());

    // Initialize a Counter object 'w' to store the occurrences of numbers
    int* w = store(input());

    // Initialize a counter 'c' to store the result
    int c = find(w, n);

    // Print the result divided by 2
    printf("%d\n", c / 2);

    // Free memory
    free(w);

    return 0;
}

