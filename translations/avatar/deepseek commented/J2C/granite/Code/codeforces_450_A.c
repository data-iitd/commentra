

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m); // Read the first integer input, which represents the number of elements
    int *arr = (int *)malloc(n * sizeof(int)); // Allocate memory for the array
    int *idx = (int *)malloc(n * sizeof(int)); // Allocate memory for the indices
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]); // Read each element and store it in the array
        idx[i] = i + 1; // Store the corresponding index in the idx array
    }
    
    int ans = 0; // Initialize ans to store the result
    
    for (int i = 0; i < n; i++) {
        while (arr[i] > m) {
            arr[i] -= m; // Subtract m from the element
            int temp = arr[i];
            arr[i] = arr[n - 1];
            arr[n - 1] = temp;
            temp = idx[i];
            idx[i] = idx[n - 1];
            idx[n - 1] = temp;
        }
    }
    
    for (int i = 0; i < n; i++) {
        if (arr[i] <= m) { // Check if the element is less than or equal to m
            ans = idx[i]; // Assign the corresponding index to ans
            break;
        }
    }
    
    printf("%d\n", ans); // Print the index of the last remaining element
    
    free(arr); // Free the memory allocated for the array
    free(idx); // Free the memory allocated for the indices
    
    return 0;
}
