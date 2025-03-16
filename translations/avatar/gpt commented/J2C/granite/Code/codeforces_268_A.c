
#include <stdio.h> // Include the standard input/output library

int main() {
    int n; // Declare and initialize the variable n to store the number of elements
    scanf("%d", &n); // Read the number of elements from the user

    int h[n]; // Declare an array h to store the first set of integers
    int g[n]; // Declare an array g to store the second set of integers

    for (int i = 0; i < n; i++) {
        scanf("%d", &h[i]); // Read n integers into the first array (h)
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &g[i]); // Read n integers into the second array (g)
    }

    int result = 0; // Initialize a variable to store the result of matching elements

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (h[i] == g[j]) { // If a match is found, increment the result counter
                result++; // Incrementing the count of matches
            }
        }
    }

    printf("%d", result); // Output the total number of matches found

    return 0; // Return 0 to indicate successful program execution
}
