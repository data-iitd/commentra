#include <stdio.h> // Including standard input-output library

void print(int x, int n); // Function prototype for print

int main() { // Main function to start the execution of the program
    int n, x; // Declaring variables for user input
    scanf("%d", &n); // Reading the first integer input from the user
    scanf("%d", &x); // Reading the second integer input from the user
    print(x, n); // Calling the print function with x and n as arguments
    return 0; // Returning 0 to indicate successful execution
}

void print(int x, int n) { // Function to print the answer based on the given input
    int max = n * 2 - 1; // Calculating the maximum index for the sequence

    if (x == 1 || x == max) { // Checking if x is the first or last index in the sequence
        printf("No\n"); // If true, print "No" and return
        return;
    }

    printf("Yes\n"); // If false, print "Yes"
    for (int i = x + n - 1; i < x + n + max - 1; i++) { // Looping through the range
        printf("%d\n", (i % max) + 1); // Printing each element in the sequence
    }
}

// <END-OF-CODE>
