#include <stdio.h>

int main() {
    int n; // Initialize an integer variable 'n' to store the number of elements in the array 'a'

    // Read the number of elements from the standard input
    scanf("%d", &n);

    // Allocate memory for the array 'a' of size 'n'
    int a[n];

    // Read 'n' integers from the standard input and store them in the array 'a'
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]); // Read an integer from the standard input and store it in the 'i'-th position of the array 'a'
    }

    int ans = 0; // Initialize an integer variable 'ans' to store the answer
    int ok = 1; // Initialize an integer variable 'ok' to keep track of the loop condition

    // Main logic of the program starts here
    while (ok) {
        for (int i = 0; i < n; i++) { // Iterate through all the elements in the array 'a'
            if (a[i] % 2 == 1) { // Check if the 'i'-th element of the array 'a' is odd
                printf("%d\n", ans); // If yes, print the answer and exit the program
                return 0;
            } else { // If the 'i'-th element of the array 'a' is even, divide it by 2
                a[i] /= 2;
            }
        }
        ans++; // Increment the answer by 1 for each iteration of the outer loop
        ok = 0; // Set the loop condition to false to exit the loop if all elements in the array 'a' become even
    }

    // Print the final answer if all elements in the array 'a' become even
    printf("%d\n", ans);
    
    return 0; // Return 0 to indicate successful completion of the program
}

// <END-OF-CODE>
