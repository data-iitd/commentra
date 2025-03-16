#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    // Read the number of elements
    scanf("%d", &n);
    
    int *a = (int *)malloc(n * sizeof(int));
    
    // Read the list of integers
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    
    // Sort the array
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] > a[j]) {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    
    // Find the largest number that leaves a remainder when divided by any number in the list
    int result = (a[0] == 0) ? -1 : a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] % a[0] != 0) {
            result = a[0];
            break;
        }
    }
    
    printf("%d\n", result);
    
    free(a);
    return 0;
}

// <END-OF-CODE>
