#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    // Read an input line (not used in the logic)
    char line[100];
    fgets(line, sizeof(line), stdin);
    
    // Read a line of integers, split by spaces, and convert them to a list of integers
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    
    // Sort the list of integers in ascending order
    qsort(a, n, sizeof(int), compare);
    
    // Iterate through the sorted list starting from the second element
    for (int i = 1; i < n; i++) {
        // Check if the current element is different from the previous one
        // and if it is less than double the previous element
        if (a[i] != a[i - 1] && a[i] < a[i - 1] * 2) {
            // If the condition is met, print 'YES' and return
            printf("YES\n");
            return 0;
        }
    }
    
    // If no such pair is found, print 'NO'
    printf("NO\n");
    return 0;
}
