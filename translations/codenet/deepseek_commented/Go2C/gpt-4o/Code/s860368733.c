#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m; // Declare variables to store the number of elements and comparisons
    scanf("%d %d", &n, &m); // Read the number of elements and comparisons from standard input
    int *h = (int *)malloc(n * sizeof(int)); // Create an array to store the heights of the elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &h[i]); // Read the heights of the elements from standard input
    }
    
    int *counter = (int *)calloc(n + 1, sizeof(int)); // Create an array to keep track of elements that cannot be the highest
<<<<<<< HEAD
    for (int i = 0; i < m; i++) {
        int a, b; // Declare variables to store the indices of the elements being compared
=======
    int a, b; // Declare variables to store the indices of the elements being compared
    for (int i = 0; i < m; i++) {
>>>>>>> 98c87cb78a (data updated)
        scanf("%d %d", &a, &b); // Read each comparison from standard input
        if (h[a - 1] < h[b - 1]) { // Check if the height of the first element is less than the second
            counter[a] = 1; // Mark the first element as not being the highest
        } else if (h[a - 1] > h[b - 1]) { // Check if the height of the first element is greater than the second
            counter[b] = 1; // Mark the second element as not being the highest
        } else { // Check if the heights of the two elements are equal
            counter[a] = 1; // Mark both elements as not being the highest
            counter[b] = 1;
        }
    }
    
    int count = 0; // Variable to count the number of elements that can be the highest
    for (int i = 1; i <= n; i++) {
        if (counter[i] == 0) {
            count++; // Increment count for elements that can be the highest
        }
    }
    
    printf("%d\n", count); // Print the number of elements that can be the highest

    free(h); // Free the allocated memory for heights
    free(counter); // Free the allocated memory for counter
    return 0;
}
<<<<<<< HEAD

// <END-OF-CODE>
=======
>>>>>>> 98c87cb78a (data updated)
