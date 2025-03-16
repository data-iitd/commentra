#include <stdio.h>

// Function to compare two integers for qsort
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    // Create an array to hold three integers
    int in[3];

    // Read three integers from standard input
    scanf("%d %d %d", &in[0], &in[1], &in[2]);

    // Sort the integers in ascending order
    qsort(in, 3, sizeof(int), compare);

    // Calculate the result based on the sorted integers
    // The result is computed as: (largest number * 10) + (second largest number) + (smallest number)
    printf("%d\n", in[2] * 10 + in[1] + in[0]);

    return 0;
}
