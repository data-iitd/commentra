#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

char* s() {
    // Read an input line (not used in the logic)
    char input[100];
    fgets(input, sizeof(input), stdin);
    
    // Read a line of integers
    int a[100];
    int n = 0;
    
    // Read integers from input
    while (scanf("%d", &a[n]) == 1) {
        n++;
    }
    
    // Sort the array of integers in ascending order
    qsort(a, n, sizeof(int), compare);
    
    // Iterate through the sorted array starting from the second element
    for (int i = 1; i < n; i++) {
        // Check if the current element is different from the previous one
        // and if it is less than double the previous element
        if (a[i] != a[i - 1] && a[i] < a[i - 1] * 2) {
            // If the condition is met, return "YES"
            return "YES";
        }
    }
    
    // If no such pair is found, return "NO"
    return "NO";
}

int main() {
    // Call the function and print the result
    printf("%s\n", s());
    return 0;
}

// <END-OF-CODE>
