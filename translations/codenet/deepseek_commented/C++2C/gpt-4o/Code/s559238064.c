<<<<<<< HEAD
#include <stdio.h>      // Include stdio.h for input and output operations
=======
#include <stdio.h>      // Include stdio for input and output operations
>>>>>>> 98c87cb78a (data updated)
#include <string.h>     // Include string.h for string manipulation functions

int main()
{
    char z[100001];    // Declare a string variable to store input string (with a maximum size)
    scanf("%s", z);    // Read input string from standard input
    int a = strlen(z); // Calculate the size of the string and store it in a

    for (int i = 0; i < a - 1; i++) // Iterate through the string
    {
        if (z[i] == z[i + 1]) // Check if any two consecutive characters are the same
        {
            printf("Bad\n"); // Print "Bad" if a pair is found and exit
            return 0;
        }
    }
    printf("Good\n"); // Print "Good" if no pair is found
    return 0; // Return 0 to indicate successful execution
}

// <END-OF-CODE>
