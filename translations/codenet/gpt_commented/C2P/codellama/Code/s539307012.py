#include<stdio.h>

int main(void) {
    # Declare variables
    n = 0
    x = 0
    min = 0
    m = 0
    i = 0

    # Read the number of elements (n), a value (x), and the initial minimum value (min)
    scanf("%d %d %d", &n, &x, &min)

    # Adjust x by subtracting the initial minimum value
    x -= min

    # Loop through the remaining n-1 elements to read their values
    for i in range(1, n):
        # Read the next element into variable m
        scanf("%d", &m)

        # Subtract the current element from x
        x -= m

        # Update min if the current element is smaller than the current minimum
        if min > m:
            min = m

    # Calculate and print the result based on the number of elements and the adjusted x divided by the minimum value
    printf("%d\n", n + x / min)

    return 0 # Return 0 to indicate successful completion of the program
}
