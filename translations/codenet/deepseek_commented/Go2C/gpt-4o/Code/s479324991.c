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
    
    // Read the number of elements
    scanf("%d", &n);
    
    // Initialize an array to hold the float values
    float *arr = (float *)malloc(n * sizeof(float));
    
    // Read each integer and convert it to float, then store in the array
    for (int i = 0; i < n; i++) {
        int temp;
        scanf("%d", &temp);
        arr[i] = (float)temp;
    }
    
    // Sort the array of float values
    sort(arr, n);
    
    // Initialize a variable to keep track of the running average
    float prev = arr[0];
    
    // Iterate through the sorted array to calculate the average
    for (int i = 1; i < n; i++) {
        prev = (prev + arr[i]) / 2;
    }

    // Print the final average
    printf("%f\n", prev);
    
<<<<<<< HEAD
    // Free the allocated memory
=======
    // Free allocated memory
>>>>>>> 98c87cb78a (data updated)
    free(arr);
    
    return 0;
}

// <END-OF-CODE>
