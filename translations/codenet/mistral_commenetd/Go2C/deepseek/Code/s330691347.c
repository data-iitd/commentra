#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to represent a single data point
typedef struct {
    char X[100];
} Data;

// Define a type Datas as a pointer to Data
typedef Data* Datas;

// Function to compare two Data points
int compare(const void *a, const void *b) {
    Data *dataA = (Data *)a;
    Data *dataB = (Data *)b;
    return strcmp(dataA->X, dataB->X);
}

int main() {
    // Initialize variables to read input
    int N, L;

    // Read number of data points N from the input
    scanf("%d", &N);

    // Read number of queries L from the input
    scanf("%d", &L);

    // Allocate memory for the slice of Data type named s
    Datas s = (Datas)malloc(N * sizeof(Data));

    // Read data points X from the input and store them in the slice s
    for (int i = 0; i < N; i++) {
        scanf("%s", s[i].X);
    }

    // Sort the slice s using qsort and the compare function
    qsort(s, N, sizeof(Data), compare);

    // Initialize an empty string ans to store the concatenated X values
    char ans[10000];
    ans[0] = '\0';

    // Iterate through the slice s and concatenate X values to the string ans
    for (int i = 0; i < N; i++) {
        strcat(ans, s[i].X);
    }

    // Print the concatenated string ans to the console
    printf("%s\n", ans);

    // Free the allocated memory for s
    free(s);

    return 0;
}
