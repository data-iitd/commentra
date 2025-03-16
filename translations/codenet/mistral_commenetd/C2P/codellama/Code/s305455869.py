
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <limits.h>
#include <math.h>

int main(int argc, char *argv[])
{
    int a, b; // Declare two integer variables 'a' and 'b'
    int ans; // Declare an integer variable 'ans' to store the answer

    scanf("%d %d", &a, &b); // Read two integers from the standard input and store them in variables 'a' and 'b'

    ans = 0; // Initialize the answer variable 'ans' to zero

    # If 'a' is greater than or equal to 13
    if (a >= 13):
        ans = b; // If 'a' is greater than or equal to 13, then the answer is 'b'

    # Else if 'a' is greater than or equal to 6
    elif (a >= 6):
        ans = b/2; // If 'a' is greater than or equal to 6, then the answer is half of 'b'

    print(ans); // Print the answer to the standard output

    return 0; // Indicate successful termination of the program
}

