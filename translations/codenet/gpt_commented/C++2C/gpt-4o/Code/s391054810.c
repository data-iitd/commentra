#include <stdio.h>

int main()
{
    // Declare variables to hold the height and width of the rectangle,
    // as well as the height and width of the cut-out section.
    int h, w, hh, ww;

    // Read the height and width of the rectangle, and the height and width of the cut-out section from user input.
    scanf("%d %d %d %d", &h, &w, &hh, &ww);

    // Calculate the area of the remaining rectangle after the cut-out section
    // by subtracting the cut-out dimensions from the original dimensions.
    // The area is calculated as (remaining height) * (remaining width).
    printf("%d\n", (h - hh) * (w - ww));

    // Return 0 to indicate that the program finished successfully.
    return 0;
}

// <END-OF-CODE>
