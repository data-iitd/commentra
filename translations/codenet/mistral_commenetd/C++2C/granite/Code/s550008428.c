

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(){
    int s, x, d=2; // Initialize variables s, x, and d with initial values

    scanf("%d", &s); // Read an integer value from the standard input and assign it to variable s
    bool a[s+1]; // Create an array named a of size s+1 initialized with all false values
    a[s] = true; // Set the value of a[s] to true

    while(1) { // Start an infinite loop
        if(s%2==0){ // Check if s is even
            x = s/2; // Calculate the half of s and assign it to x
            if(a[x]) { // Check if a[x] is true
                printf("%d\n", d); // If yes, print the value of d and exit the program
                return 0;
            }
            a[x] = true; // If not, set a[x] to true and assign it to s for the next iteration
        } else { // If s is odd
            x = 3*s + 1; // Calculate 3s + 1 and assign it to x
            if(a[x]) { // Check if a[x] is true
                printf("%d\n", d); // If yes, print the value of d and exit the program
                return 0;
            }
            a[x] = true; // If not, set a[x] to true and assign it to s for the next iteration
        }
        s = x; // Update the value of s with the new value of x
        d++; // Increment the value of d for each iteration
    }

    printf("%d\n", d); // Print the value of d if the loop terminates due to a condition other than finding a duplicate number in the set

    return 0; // Exit the program with a return value of 0
}

