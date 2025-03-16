#include <stdio.h>
#include <stdlib.h>

int main() {
    // Read the number of elements
    int n;
    scanf("%d", &n);

    // Initialize an array to store the elements
    int *a = (int *)malloc(n * sizeof(int));
    
    // Input the elements into the array
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    // Initialize the answer counter and a flag for the loop
    int ans = 0;
    int ok = 1;

    // Loop until an odd number is found in the array
    while(ok) {
        // Check each element in the array
        for(int i = 0; i < n; i++) {
            // If the current element is odd, print the answer and exit
            if(a[i] % 2 == 1) {
                printf("%d\n", ans);
                free(a); // Free the allocated memory
                return 0;
            }
            // If the current element is even, divide it by 2
            else {
                a[i] /= 2;
            }
        }
        // Increment the answer counter for each complete iteration
        ans++;
    }

    // Output the final count of divisions by 2 before encountering an odd number
    printf("%d\n", ans);
    free(a); // Free the allocated memory
}
