#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    // Read the first integer `n` from the standard input stream and assign it to the variable `n`
    int n;
    scanf("%d", &n);

    // Create a new long array `arr` of size `n`
    long *arr = (long *) malloc(n * sizeof(long));

    // Use a for loop to read `n` integers from the standard input stream and assign them to the corresponding elements of the array `arr`
    for (int i = 0; i < n; i++) {
        scanf("%ld", &arr[i]);
    }

    // Initialize the variable `answer` with the absolute value of the first element of the array `arr`
    long answer = abs(arr[0]);

    // Use a for loop to iterate over the remaining elements of the array `arr` and calculate the absolute difference between each element and the previous one, adding the result to the variable `answer`
    for (int i = 1; i < n; i++) {
        answer += abs(arr[i] - arr[i - 1]);
    }

    // Print the value of the variable `answer` to the standard output stream
    printf("%ld\n", answer);

    // Free the memory allocated to the array `arr`
    free(arr);

    return EXIT_SUCCESS;
}

