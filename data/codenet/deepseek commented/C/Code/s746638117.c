#include<stdio.h> // Step 1: Include the standard input/output library.

int main(){ // Step 2: Define the main function.
        int a,b,ar,le; // Step 3: Declare integer variables a, b, ar, and le.
        scanf("%d %d", &a, &b); // Step 4: Read two integers from the user.
        ar=a*b; // Step 5: Calculate the area of a rectangle (ar) by multiplying a and b.
        le=2*(a+b); // Step 6: Calculate the perimeter of a rectangle (le) by doubling the sum of a and b.
        printf("%d %d\n",ar,le); // Step 7: Print the area and perimeter.
        return 0; // Step 8: Return 0 to indicate successful execution.
}
