#include <stdio.h>
#include <stdlib.h>

int main() {
    // Read four integers from input
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    
    // Check conditions to determine the output
    if (c > b) {
        // If c is greater than b, output 0
        printf("0\n");
    } else if (a > d) {
        // If a is greater than d, output 0
        printf("0\n");
    } else if (a < c) {
        // If a is less than c, calculate and output the difference
        printf("%d\n", (b < d ? b : d) - c);
    } else {
        // Create an array to hold the four integers
        int arr[4] = {a, b, c, d};
        
        // Sort the array to find the second largest and third largest values
        qsort(arr, 4, sizeof(int), (int (*)(const void *, const void *))compare);
        
        // Output the difference between the second largest and third largest values
        printf("%d\n", arr[2] - arr[1]);
    }
    
    return 0;
}

// Comparison function for qsort
int compare(const int *a, const int *b) {
    return (*a - *b);
}

// <END-OF-CODE>
