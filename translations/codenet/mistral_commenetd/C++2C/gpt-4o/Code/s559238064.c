#include <stdio.h>
#include <string.h>

int main()
{
    char z[100001]; // Initialize a character array to store input string
    scanf("%s", z); // Read input string from standard input

    int a = strlen(z); // Assign size of the string to variable 'a'

    // Check if there are any consecutive identical characters in the string
    for (int i = 0; i < a - 1; i++)
    {
        // Check if current character is same as next character
        if (z[i] == z[i + 1])
        {
            // If yes, print "Bad" and exit the program
            printf("Bad\n");
            return 0;
        }
    }
    // If no consecutive identical characters are found, print "Good"
    printf("Good\n");
    
    return 0; // Return 0 to indicate successful completion
}

// <END-OF-CODE>
