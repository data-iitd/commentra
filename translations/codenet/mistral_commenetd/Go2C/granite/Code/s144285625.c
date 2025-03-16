

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Initializing scanner for reading input from stdin
    char input[1000];
    fgets(input, 1000, stdin);

    // Reading the number of elements in the array
    int n = atoi(strtok(input, " "));

    // Allocating memory for the array
    int ar[3*n];

    // Reading elements of the array
    char *token = strtok(NULL, " ");
    for (int i = 0; i < 3*n; i++) {
        // Reading next integer and storing it in the array
        ar[i] = atoi(token);
        token = strtok(NULL, " ");
    }

    // Sorting the array in ascending order
    qsort(ar, 3*n, sizeof(int), compare);

    // Calculating the sum of elements at index 3n-2i-1 in the sorted array
    int sum = 0;
    for (int i = 0; i < n; i++) {
        // Adding the element at index 3n-2i-1 to the sum
        sum += ar[3*n-(i+1)*2];
    }

    // Printing the result
    printf("%d\n", sum);

    return 0;
}

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

