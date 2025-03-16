#include <stdio.h>

int main(void) {
    // Declare two integer variables x and y
    int x, y;

    // Read an integer value from the user and store it in variable x
    scanf("%d", &x);

    // Calculate the cube of x and store the result in variable y
    y = x * x * x;

    // Print the result (the cube of x) to the console
    printf("%d\n", y);

    // Return 0 to indicate successful completion of the program
    return 0;
}
