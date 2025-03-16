
#include<stdio.h> // Include the standard input/output library for input and output
#include<algorithm> // Include the algorithm library for the swap function

int main() {
    int a, b, c; // Declare three integer variables to hold the input values
    scanf("%d %d %d", &a, &b, &c); // Read three integers from the user

    // Check if 'a' is greater than 'b', if so, swap their values
    if (a > b) {
        swap(a, b);
    }

    // Check if 'b' is greater than 'c', if so, swap their values
    if (b > c) {
        swap(b, c);
    }

    // Check again if 'a' is greater than 'b', if so, swap their values
    if (a > b) {
        swap(a, b);
    }

    // Output the sorted values of a, b, and c
    printf("%d %d %d\n", a, b, c);

    return 0; // Return 0 to indicate successful completion of the program
}
