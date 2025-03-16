#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_INPUT 1000
#define MARCH_COUNT 5

// Function to read an integer from input
int read_int() {
    int n;
    scanf("%d", &n);
    return n;
}

// Function to read a string from input
void read_string(char *str) {
    scanf("%s", str);
}

int main() {
    // Define constants and global variables
    int N = read_int();  // Number of inputs
    char S[MAX_INPUT][100];  // List of strings as inputs
    int march_lis[MARCH_COUNT] = {0};  // List to store the count of each marching order
    int ans = 0;  // Variable to store the answer
    char march[MARCH_COUNT] = {'M', 'A', 'R', 'C', 'H'};  // List of marching orders

    // Read input strings
    for (int i = 0; i < N; i++) {
        read_string(S[i]);
    }

    // Iterate through each string in S and increment the count of the corresponding marching order in march_lis
    for (int i = 0; i < N; i++) {
        char first_char = S[i][0];
        for (int j = 0; j < MARCH_COUNT; j++) {
            if (first_char == march[j]) {
                march_lis[j]++;
                break;
            }
        }
    }

    // Calculate the answer by finding the triple product of the counts of each marching order
    for (int i = 0; i < MARCH_COUNT; i++) {
        for (int j = i + 1; j < MARCH_COUNT; j++) {
            for (int k = j + 1; k < MARCH_COUNT; k++) {
                ans += march_lis[i] * march_lis[j] * march_lis[k];
            }
        }
    }

    // Print the answer
    printf("%d\n", ans);

    return 0;
}

// <END-OF-CODE>
