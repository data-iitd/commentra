#include <stdio.h>

int main() {
    int n;
    // Reading the number of elements in the list 'w'
    scanf("%d", &n);
    
    int w[n]; // Array to store the elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &w[i]); // Reading each element into the array
    }

    int d[n]; // Array to store the indices of the elements that satisfy the condition
    int count = 0; // Counter for the number of valid indices

    // Iterating through each element 'i' in the array 'w'
    for (int i = 0; i < n; i++) {
        // Calculating the sum of all elements
        int sum = 0;
        for (int j = 0; j < n; j++) {
            sum += w[j];
        }
        
        // Checking if the average of the remaining sum equals the current element 'w[i]'
        if ((sum - w[i]) / (n - 1) == w[i]) {
            // If the condition is true, store the index 'i + 1' in the array 'd'
            d[count++] = i + 1;
        }
    }

    // Printing the length of the list 'd'
    printf("%d\n", count);
    
    // Printing the elements of the list 'd' separated by a space
    for (int i = 0; i < count; i++) {
        printf("%d", d[i]);
        if (i < count - 1) {
            printf(" "); // Print space between numbers
        }
    }
    printf("\n");

    return 0;
}

// <END-OF-CODE>
