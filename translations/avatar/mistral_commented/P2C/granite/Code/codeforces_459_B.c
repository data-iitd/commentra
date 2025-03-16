

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n); // Read the number of elements in the list
    int *l1 = (int *)malloc(n * sizeof(int)); // Allocate memory for the list
    for (int i = 0; i < n; i++) {
        scanf("%d", &l1[i]); // Read the list elements
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (l1[i] > l1[j]) {
                int temp = l1[i];
                l1[i] = l1[j];
                l1[j] = temp;
            }
        }
    }
    int a = l1[n - 1]; // Assign the last element of the sorted list to the variable a
    int b = l1[0]; // Assign the first element of the sorted list to the variable b
    if (a == b) { // Check if the first and the last elements are equal
        printf("%d %d\n", a - b, (n * (n - 1)) / 2); // If so, calculate and print the result
    } else {
        int ac = 0, bc = 0; // Initialize the counters for the occurrences of a and b
        for (int i = 0; i < n; i++) {
            if (l1[i] == a) {
                ac++; // Increment the counter for the occurrences of a
            }
            if (l1[i] == b) {
                bc++; // Increment the counter for the occurrences of b
            }
        }
        printf("%d %d\n", a - b, ac * bc); // Print the result
    }
    free(l1); // Free the allocated memory
    return 0;
}

