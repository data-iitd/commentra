#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to represent a single data point
typedef struct {
    char X[100]; // Assuming a maximum length of 99 characters for the string
} Data;

// Function to compare two Data structures for qsort
int compare(const void *a, const void *b) {
    return strcmp(((Data *)a)->X, ((Data *)b)->X);
}

// Main function starts here
int main() {
    int N, L;

    // Read number of data points N from the input
    scanf("%d", &N);

    // Read number of queries L from the input
    scanf("%d", &L);

    // Allocate memory for N data points
    Data *s = (Data *)malloc(N * sizeof(Data));

    // Read data points X from the input and store them in the array s
    for (int i = 0; i < N; i++) {
        scanf("%s", s[i].X);
    }

    // Sort the array s in ascending order based on X field
    qsort(s, N, sizeof(Data), compare);

    // Initialize an empty string ans to store the concatenated X values
    char ans[10000] = ""; // Assuming a maximum length for the concatenated string

    // Iterate through the array s and concatenate X values to the string ans
    for (int i = 0; i < N; i++) {
        strcat(ans, s[i].X);
    }

    // Print the concatenated string ans to the console
    printf("%s\n", ans);

    // Free the allocated memory
    free(s);

    return 0;
}

// <END-OF-CODE>
