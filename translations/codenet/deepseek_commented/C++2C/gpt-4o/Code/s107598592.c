#include <stdio.h>  // Include the standard input-output library for printf and scanf.
#include <stdlib.h> // Include the standard library for memory allocation and other utilities.

void sort(int* arr, int n) { // Function to sort an array using bubble sort (for simplicity).
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j + 1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int N; 
    scanf("%d", &N); // Read the number of elements N from the standard input.
    
    int* X = (int*)malloc(N * sizeof(int)); // Dynamically allocate memory for vector X.
    int* Y = (int*)malloc(N * sizeof(int)); // Dynamically allocate memory for vector Y.
    
    // Read N elements into vector X and simultaneously copy them to vector Y.
    for (int i = 0; i < N; i++) { 
        scanf("%d", &X[i]); 
        Y[i] = X[i]; 
    }
    
    // Sort the vector Y in ascending order.
    sort(Y, N);
    
    // Calculate the median of the sorted vector Y.
<<<<<<< HEAD
    int y = Y[N / 2]; // For simplicity, this assumes N is odd. Adjust as needed for even N.
=======
    int y = Y[N / 2]; // This assumes N is odd; for even N, you would need to average the two middle elements.
>>>>>>> 98c87cb78a (data updated)
    
    // Iterate through each element in vector X and output the appropriate median value based on the comparison with y.
    for (int i = 0; i < N; i++) {
        if (X[i] < y) {
            printf("%d\n", y); // If the element in X is less than the median, output the median.
        } else {
            printf("%d\n", y - 1); // Otherwise, output the median minus one.
        }
    }
    
    free(X); // Free the allocated memory for vector X.
    free(Y); // Free the allocated memory for vector Y.
    
    return 0; // Return 0 to indicate successful execution.
}

// <END-OF-CODE>
