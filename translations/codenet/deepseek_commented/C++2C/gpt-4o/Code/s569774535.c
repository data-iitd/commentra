#include <stdio.h>  // Include the standard input-output library
<<<<<<< HEAD
#include <stdlib.h> // Include the standard library for dynamic memory management
=======
>>>>>>> 98c87cb78a (data updated)

int main() {
    int n;
    scanf("%d", &n);  // Read the integer n
<<<<<<< HEAD
    int *a = (int *)malloc(n * sizeof(int)); // Dynamically allocate an array of size n
    for (int i = 0; i < n; i++) {
=======
    int a[n];  // Declare an array of size n
    for(int i = 0; i < n; i++) {
>>>>>>> 98c87cb78a (data updated)
        scanf("%d", &a[i]);  // Read n integers into the array a
    }

    int ans = 0;  // Initialize ans to 0
    int ok = 1;   // Initialize ok to true (1)
<<<<<<< HEAD
    while (ok) {  // Start the main loop
        for (int i = 0; i < n; i++) {  // Iterate over each element in the array a
            if (a[i] % 2 == 1) {  // Check if the element is odd
                printf("%d\n", ans);  // Print the current value of ans and exit
                free(a); // Free the allocated memory
=======
    while(ok) {  // Start the main loop
        for(int i = 0; i < n; i++) {  // Iterate over each element in the array a
            if(a[i] % 2 == 1) {  // Check if the element is odd
                printf("%d\n", ans);  // Print the current value of ans and exit
>>>>>>> 98c87cb78a (data updated)
                return 0;
            } else {  // If the element is even
                a[i] /= 2;  // Divide the element by 2
            }
        }
        ans++;  // Increment ans after processing all elements
    }

    printf("%d\n", ans);  // Print the final value of ans
<<<<<<< HEAD
    free(a); // Free the allocated memory
    return 0;
=======
    return 0;  // Return 0 to indicate successful completion
>>>>>>> 98c87cb78a (data updated)
}

// <END-OF-CODE>
