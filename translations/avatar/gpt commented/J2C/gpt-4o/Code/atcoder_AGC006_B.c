#include <stdio.h> // Including standard input-output library

void print(int x, int n) {
    // Calculating the maximum value based on n
    int max = n * 2 - 1;

    // Checking if x is equal to 1 or max, if so, print "No" and exit the function
    if (x == 1 || x == max) {
        printf("No\n");
        return; // Exit the function early
    }

    // If x is valid, print "Yes"
    printf("Yes\n");

    // Generate and print the sequence of numbers based on the input x and n
    for (int i = x + n - 1; i < x + n + max - 1; i++) {
        printf("%d\n", (i % max) + 1); // Adjusting the number to fit within the range
    }
}

int main() {
    // Declaring variables for user input
    int n, x;

    // Reading two integers from user input: n and x
    scanf("%d %d", &n, &x);

    // Calling the print function with the inputs x and n
    print(x, n);

    return 0; // Indicating that the program ended successfully
}

// <END-OF-CODE>
