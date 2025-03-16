#include<stdio.h>  // Include the standard input/output library
int main(){       // Define the main function

    // Declare integer variables to store input values and intermediate results
    int a, b, c, d, i, j;

    // Read four integers from the user
    scanf("%d %d %d %d", &a, &b, &c, &d);

    // Perform multiplication operations and store the results in i and j
    i = a * b;
    j = c * d;

    // Use an if-else statement to compare the results and print the larger one
    if (i > j) {
        printf("%d\n", i);
    } else {
        printf("%d\n", j);
    }

    // Return 0 to indicate successful execution
    return 0;
}
