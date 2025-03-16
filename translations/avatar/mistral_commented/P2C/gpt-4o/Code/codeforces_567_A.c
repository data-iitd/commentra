#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    
    // Take an integer input from the user
    scanf("%d", &n);
    
    // Create an array to store the input integers
    int *lista = (int *)malloc(n * sizeof(int));
    
    // Populate the array 'lista' with integers input by the user, separated by spaces
    for (int i = 0; i < n; i++) {
        scanf("%d", &lista[i]);
    }
    
    // Iterate through each index 'i' in the array 'lista'
    for (int i = 0; i < n; i++) {
        // If 'i' is the first index
        if (i == 0) {
            // Print the difference between the second and first elements and the difference between the last and first elements
            printf("%d %d\n", lista[i + 1] - lista[i], lista[n - 1] - lista[i]);
            continue;
        }
        
        // If 'i' is the last index
        else if (i == n - 1) {
            // Print the difference between the last and second last element and the difference between the last and first element
            printf("%d %d\n", lista[n - 1] - lista[n - 2], lista[n - 1] - lista[0]);
            continue;
        }
        
        // If the difference between the current index and the previous index is greater than the difference between the next index and the current index
        else if (lista[i] - lista[i - 1] > lista[i + 1] - lista[i]) {
            // Print the difference between the next index and the current index
            printf("%d ", lista[i + 1] - lista[i]);
        }
        
        // If the difference between the current index and the previous index is less than or equal to the difference between the next index and the current index
        else {
            // Print the difference between the current index and the previous index and the difference between the current index and the first index
            printf("%d ", lista[i] - lista[i - 1]);
            if (lista[n - 1] - lista[i] > lista[i] - lista[0]) {
                printf("%d\n", lista[n - 1] - lista[i]);
            } else {
                printf("%d\n", lista[i] - lista[0]);
            }
        }
    }
    
    // Free the allocated memory
    free(lista);
    
    return 0;
}

// <END-OF-CODE>
