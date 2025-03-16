#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
<<<<<<< HEAD
    return (*(float *)a > *(float *)b) - (*(float *)a < *(float *)b);
=======
    if (*(float *)a < *(float *)b) return -1;
    if (*(float *)a > *(float *)b) return 1;
    return 0;
>>>>>>> 98c87cb78a (data updated)
}

int main() {
    int N;
    scanf("%d", &N); // Read the number of values
<<<<<<< HEAD
    float *values = malloc(N * sizeof(float)); // Allocate memory for the values
=======
    float *values = (float *)malloc(N * sizeof(float)); // Allocate memory for the values
>>>>>>> 98c87cb78a (data updated)
    for (int i = 0; i < N; i++) {
        scanf("%f", &values[i]); // Read the values into the array
    }

    qsort(values, N, sizeof(float), compare); // Sort the values in ascending order
    float generated;
    // printf("%f\n", values); // Uncomment to print the sorted values (for debugging purposes)
    for (int i = 0; i < N - 1; i++) {
        generated = (values[i] + values[i + 1]) / 2; // Calculate the average of the current and next value
        values[i + 1] = generated; // Update the next value with the calculated average
    }

    printf("%f\n", generated); // Print the final generated value
    free(values); // Free the allocated memory
    return 0;
}

// <END-OF-CODE>
