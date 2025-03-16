#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int solve(int N, int arr[]) {
    // Initialize a sum variable to 0
    int sum = 0;

    // Sort the array in ascending order
    qsort(arr, N, sizeof(int), compare);

    // Iterate through the array and count the number of elements that are less than or equal to the smallest element
    for (int i = 0; i < N; i++) {
        if (arr[i] <= arr[0]) {
            sum++;
        }
    }

    // Return the sum
    return sum;
}

int main() {
    int N;

    // Read the integer N from the input
    scanf("%d", &N);

    // Initialize an array of size N to store the integers
    int arr[N];

    // Read N integers from the input and store them in the array
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    // Print the result of the solve function
    printf("%d\n", solve(N, arr));

    return 0;
}

