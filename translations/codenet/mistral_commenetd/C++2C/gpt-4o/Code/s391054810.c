#include <stdio.h>

// Declare four integer variables: h, w, hh, and ww.
int h, w, hh, ww;

int main()
{
    // Read four integers from the standard input and assign them to the variables h, w, hh, and ww respectively.
    scanf("%d %d %d %d", &h, &w, &hh, &ww);

    // Calculate the difference between h and hh and the difference between w and ww.
    int difference_h = h - hh;
    int difference_w = w - ww;

    // Output the product of the differences to the standard output.
    printf("The area of the rectangle is: %d\n", difference_h * difference_w);

    // Return 0 to indicate successful termination of the program.
    return 0;
}

// <END-OF-CODE>
