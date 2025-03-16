#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

const char* s() {
    int n;
    // Take input from the user
    scanf("%d", &n);
    // Allocate memory for the array
    int *a = (int *)malloc(n * sizeof(int));
    
    // Read the input and store it in 'a'
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    
    // Sort the array 'a'
    qsort(a, n, sizeof(int), compare);
    
    // Iterate through the sorted array starting from the second element
    for (int i = 1; i < n; i++) {
        // Check if the current element is not equal to the previous element
        // and if the current element is less than twice the previous element
        if (a[i] != a[i - 1] && a[i] < a[i - 1] * 2) {
            // If the condition is met, return "YES"
            free(a);
            return "YES";
        }
    }
    
    // If the loop completes without finding a match, return "NO"
    free(a);
    return "NO";
}

int main() {
    // Print the result returned by the function 's()'
    printf("%s\n", s());
    return 0;
}

// <END-OF-CODE>
