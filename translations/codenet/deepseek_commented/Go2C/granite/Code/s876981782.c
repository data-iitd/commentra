
#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    scanf("%d", &N); // Read the number of values

    float *values = (float *)malloc(N * sizeof(float));
    for (int i = 0; i < N; i++) {
        scanf("%f", &values[i]); // Read the values into the array
    }

    qsort(values, N, sizeof(float), compare); // Sort the values in ascending order

    float generated = 0;
    for (int i = 0; i < N - 1; i++) {
        generated = (values[i] + values[i + 1]) / 2; // Calculate the average of the current and next value
        values[i + 1] = generated; // Update the next value with the calculated average
    }

    printf("%f\n", generated); // Print the final generated value

    free(values); // Free the allocated memory
    return 0;
}

int compare(const void *a, const void *b) {
    float fa = *(float *)a;
    float fb = *(float *)b;
    if (fa < fb) {
        return -1;
    } else if (fa > fb) {
        return 1;
    } else {
        return 0;
    }
}

