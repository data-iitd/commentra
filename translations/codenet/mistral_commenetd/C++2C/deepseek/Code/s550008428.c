#include <stdio.h>
#include <stdlib.h>

int main(){
    int s, x, d = 2; // Initialize variables s, x, and d with initial values

    scanf("%d", &s); // Read an integer value from the standard input and assign it to variable s
    int *a = (int*)malloc(sizeof(int)); // Create an empty set named a using dynamic memory allocation
    a[0] = s; // Add the value of s to the set a

    while(1) { // Start an infinite loop
        if(s % 2 == 0){ // Check if s is even
            x = s / 2; // Calculate the half of s and assign it to x
            for(int i = 0; i < d; i++){ // Check if x is already in the set a
                if(a[i] == x){ // If yes, print the value of d and exit the program
                    printf("%d\n", d);
                    free(a); // Free the allocated memory
                    return 0;
                }
            }
            d++; // Increment the size of the array a
            a = (int*)realloc(a, d * sizeof(int)); // Reallocate memory for the new element
            a[d - 1] = x; // Add x to the set a and assign it to s for the next iteration
        } else { // If s is odd
            x = 3 * s + 1; // Calculate 3s + 1 and assign it to x
            for(int i = 0; i < d; i++){ // Check if x is already in the set a
                if(a[i] == x){ // If yes, print the value of d and exit the program
                    printf("%d\n", d);
                    free(a); // Free the allocated memory
                    return 0;
                }
            }
            d++; // Increment the size of the array a
            a = (int*)realloc(a, d * sizeof(int)); // Reallocate memory for the new element
            a[d - 1] = x; // Add x to the set a and assign it to s for the next iteration
        }
        s = x; // Update the value of s with the new value of x
    }

    printf("%d\n", d); // Print the value of d if the loop terminates due to a condition other than finding a duplicate number in the set
    free(a); // Free the allocated memory

    return 0; // Exit the program with a return value of 0
}
