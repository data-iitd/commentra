#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Data structure to hold a string
typedef struct {
    char *X;
} Data;

// Comparison function for qsort
int compare(const void *a, const void *b) {
    Data *dataA = (Data *)a;
    Data *dataB = (Data *)b;
    return strcmp(dataA->X, dataB->X);
}

int main() {
    int N, L;
    scanf("%d %d", &N, &L); // Read the number of data entries and an additional integer

    Data *s = malloc(N * sizeof(Data)); // Allocate memory for N Data entries

    // Read N strings into the array s
    for (int i = 0; i < N; i++) {
        s[i].X = malloc(100 * sizeof(char)); // Allocate memory for each string (assuming max length of 99)
        scanf("%s", s[i].X); // Read each string
    }

    // Sort the array of Data entries
    qsort(s, N, sizeof(Data), compare);

    // Concatenate all strings in the sorted array into a single result
    char *ans = malloc(10000 * sizeof(char)); // Allocate memory for the concatenated result
    ans[0] = '\0'; // Initialize the result string

    for (int i = 0; i < N; i++) {
        strcat(ans, s[i].X); // Append each string to ans
    }

    printf("%s\n", ans); // Print the concatenated result

    // Free allocated memory
    for (int i = 0; i < N; i++) {
        free(s[i].X); // Free each string
    }
    free(s); // Free the array of Data
    free(ans); // Free the concatenated result

    return 0;
}

// <END-OF-CODE>
