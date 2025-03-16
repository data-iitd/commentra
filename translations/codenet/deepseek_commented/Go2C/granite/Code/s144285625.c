
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n); // Read the number of elements
    int ar[3*n]; // Create an array of size 3*n
    for (int i = 0; i < 3*n; i++) {
        scanf("%d", &ar[i]); // Populate the array with integers from input
    }
    qsort(ar, 3*n, sizeof(int), compare); // Sort the array
    int sum = 0; // Initialize sum to 0
    for (int i = 0; i < n; i++) {
        sum += ar[3*n-(i+1)*2]; // Calculate the sum of the last n elements, skipping every second element
    }
    printf("%d\n", sum); // Print the sum
    return 0;
}

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b); // Compare function for qsort
}

