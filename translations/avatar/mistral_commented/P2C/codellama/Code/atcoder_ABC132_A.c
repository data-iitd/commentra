#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to count the frequency of each character in a string
int count_frequency ( char *str )
{
    int i, j, count = 0;
    char c;

    // Iterate through each character in the string
    for ( i = 0; str [ i ] != '\0'; i++ )
    {
        // For each character, check if it is already counted
        c = str [ i ];
        for ( j = 0; j < i; j++ )
        {
            // If the character is already counted, increment the count
            if ( str [ j ] == c )
            {
                count++;
                break;
            }
        }
    }

    // Return the count
    return count;
}

int main ()
{
    // Declare a string S
    char S [ 100 ];

    // Take a string as input from the user
    printf ( "Enter a string: " );
    scanf ( "%s", S );

    // Declare a set Sa from the list of characters in the string S
    char Sa [ 100 ];
    int i, j, k = 0;

    // Iterate through each character in the string S
    for ( i = 0; S [ i ] != '\0'; i++ )
    {
        // For each character, check if it is already in the set Sa
        for ( j = 0; j < k; j++ )
        {
            // If the character is already in the set Sa, do not add it again
            if ( Sa [ j ] == S [ i ] )
                break;
        }

        // If the character is not already in the set Sa, add it to the set Sa
        if ( j == k )
            Sa [ k++ ] = S [ i ];
    }

    // Check if the length of the set Sa is equal to 2
    if ( k != 2 )
    {
        // If not, print "No" and exit the program
        printf ( "No\n" );
        return 0;
    }

    // Iterate through each character i in the set Sa
    for ( i = 0; i < k; i++ )
    {
        // For each character i, check if its frequency in the string S is equal to 2 using the count_frequency function
        if ( count_frequency ( S ) != 2 )
        {
            // If the frequency of any character is not equal to 2, print "No" and exit the program
            printf ( "No\n" );
            return 0;
        }
    }

    // If all characters have a frequency of 2, print "Yes" to indicate that the string satisfies the condition
    printf ( "Yes\n" );

    return 0;
}

