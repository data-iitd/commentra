#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sort(float arr[], int n) {
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
    // Read the number of elements
    int n;
    scanf("%d", &n);
    
    // Create an array to hold the float values
    float *arr = (float *)malloc(n * sizeof(float));
    
    // Read n integers from input and convert them to float
    for (int i = 0; i < n; i++) {
        int temp;
        scanf("%d", &temp);
        arr[i] = (float)temp;
    }
    
    // Sort the array of float values
    sort(arr, n);

    // Initialize 'prev' with the first element of the sorted array
    float prev = arr[0];
    
    // Calculate the average of the elements iteratively
    for (int i = 1; i < n; i++) {
        prev = (prev + arr[i]) / 2;
    }

    // Print the final computed average
    printf("%f\n", prev);

<<<<<<< HEAD
    // Free the allocated memory
=======
    // Free allocated memory
>>>>>>> 98c87cb78a (data updated)
    free(arr);
    
    return 0;
}

<<<<<<< HEAD
/* <END-OF-CODE> */
=======
// <END-OF-CODE>
>>>>>>> 98c87cb78a (data updated)
