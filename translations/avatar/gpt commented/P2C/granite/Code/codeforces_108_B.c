
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Read an input line (not used in the logic)
    char input[100];
    fgets(input, 100, stdin);
    
    // Read a line of integers, split by spaces, and convert them to an array of integers
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    
    // Sort the array of integers in ascending order
    qsort(a, n, sizeof(int), cmpfunc);
    
    // Iterate through the sorted array starting from the second element
    for (int i = 1; i < n; i++) {
        // Check if the current element is different from the previous one
        // and if it is less than double the previous element
        if (a[i]!= a[i - 1] && a[i] < a[i - 1] * 2) {
            // If the condition is met, return 'YES'
            printf("YES\n");
            return 0;
        }
    }
    
    // If no such pair is found, return 'NO'
    printf("NO\n");
    
    return 0;
}

int cmpfunc (const void * a, const void * b) {
   return (*(int*)a - *(int*)b);
}

