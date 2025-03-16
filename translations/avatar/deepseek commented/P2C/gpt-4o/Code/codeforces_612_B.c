#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);  // Take an integer input representing the length of the list `a`
    
    int *a = (int *)malloc(n * sizeof(int));  // Dynamically allocate memory for list `a`
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);  // Take space-separated integers and store them in `a`
    }
    
    int *b = (int *)malloc(n * sizeof(int));  // Dynamically allocate memory for list `b`
    for (int i = 0; i < n; i++) {
        b[a[i] - 1] = i;  // Assign the index of each element in `a` to the corresponding position in `b`
    }
    
    int res = 0;  // Initialize the result variable `res` to 0
    
    // Calculate the sum of absolute differences between the positions of consecutive elements in `b`
    for (int i = 1; i < n; i++) {
        res += abs(b[i] - b[i - 1]);
    }
    
    printf("%d\n", res);  // Print the result
    
    free(a);  // Free the allocated memory for `a`
    free(b);  // Free the allocated memory for `b`
    
    return 0;
}  // <END-OF-CODE>
