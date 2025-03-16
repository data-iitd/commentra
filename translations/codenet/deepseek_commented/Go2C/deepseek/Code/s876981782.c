#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(double*)a - *(double*)b);
}

int main() {
    int N;
    scanf("%d", &N); // Read the number of values
    double values[N];
    for (int i = 0; i < N; i++) {
        scanf("%lf", &values[i]); // Read the values into the array
    }

    qsort(values, N, sizeof(double), compare); // Sort the values in ascending order
    double generated = 0;
    for (int i = 0; i < N - 1; i++) {
        generated = (values[i] + values[i + 1]) / 2; // Calculate the average of the current and next value
        values[i + 1] = generated; // Update the next value with the calculated average
    }

    printf("%lf\n", generated); // Print the final generated value
    return 0;
}
