#include <stdio.h>
#include <stdlib.h>

void sort(float *arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                float temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n;
    // Read the number of elements in the array
    scanf("%d", &n);

    // Allocate memory for the array of size n
    float *arr = (float *)malloc(n * sizeof(float));

    // Read n integers from the standard input and store them in the array
    for (int i = 0; i < n; i++) {
        int temp;
        scanf("%d", &temp);
        arr[i] = (float)temp;
    }

    // Sort the array in ascending order
    sort(arr, n);

    // Initialize a variable prev to store the previous element in the sorted array
    float prev = arr[0];

    // Iterate through the sorted array from the second element to the last
    for (int i = 1; i < n; i++) {
        // Calculate the average of the previous and current elements
        prev = (prev + arr[i]) / 2;
    }

    // Print the result to the standard output
    printf("%f\n", prev);

    // Free the allocated memory
    free(arr);

    return 0;
}

// <END-OF-CODE>
