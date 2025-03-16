#include <stdio.h>  // Include header for standard input/output functions
#include <algorithm> // Include header for the sort function

int main() {
    int s[11], i; // Declare an array to store the input numbers and a variable for the loop

    // Step 3: Read input numbers into the array
    for(i = 0; i < 10; i++) {
        scanf("%d", &s[i]); // Read input and store it in the array
    }

    // Step 4: Sort the array
    qsort(s, 10, sizeof(int), (int (*)(const void *, const void *))compare); // Sort the array in ascending order

    // Step 5: Print the last four numbers of the sorted array
    for(i = 9; i > 6; i--) {
        printf("%d\n", s[i]); // Print the last four numbers
    }

    return 0; // Return 0 to indicate successful execution
}

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}
