#include <stdio.h>

// Function to sort an array of integers in ascending order
void sort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                // Swap arr[j] and arr[j+1]
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main() {
    // Initialize an integer array named in with a length of 3
    int in[3];

    // Read three integers from the standard input and store them in the array in
    scanf("%d %d %d", &in[0], &in[1], &in[2]);

    // Sort the integers in ascending order using the sort function
    sort(in, 3);

    // Multiply the last integer by 10 and add the second last and the last integer
    // Then print the result using printf
    printf("%d\n", in[2] * 10 + in[1] + in[0]);

    return 0;
}
