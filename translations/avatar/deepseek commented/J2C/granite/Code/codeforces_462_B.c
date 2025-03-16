
#include <stdio.h> // Include necessary header files for input/output operations
#include <stdlib.h> // Include necessary header files for utility classes

typedef struct c462b { // Define the structure for c462b objects
    int left; // Property to store the count
} c462b;

int cmpfunc ( const void * a, const void * b ) { // Function to compare two c462b objects based on their left properties
    return ( ( c462b * ) a )->left - ( ( c462b * ) b )->left ; // Return the difference in left properties
}

int main ( ) { // Main function definition
    int n, k; // Declare variables to store the length of the string and a parameter for some operation
    scanf ( "%d %d", &n, &k ); // Read the length of the string and the parameter from standard input
    c462b * cards = ( c462b * ) malloc ( 26 * sizeof ( c462b ) ); // Allocate memory for an array of c462b objects with 26 elements
    for ( int i = 0 ; i < 26 ; i ++ ) { // Loop through the array to initialize each element
        cards [ i ].left = 0; // Initialize each c462b object's left property to zero
    }
    char s [ 100001 ]; // Declare a character array to store the string
    scanf ( "%s", s ); // Read the string from standard input
    for ( int t = 0 ; t < n ; t ++ ) { // Loop through the string to count occurrences
        cards [ s [ t ] - 'A' ].left ++ ; // Increment the left property of the corresponding c462b object
    }
    long long ans = 0; // Declare a variable to store the answer
    for ( int i = 0 ; i < k ; i ++ ) { // Loop k times to calculate the answer
        qsort ( cards, 26, sizeof ( c462b ), cmpfunc ); // Sort the cards array
        long long change = ( long long ) fmin ( cards [ 25 ].left, k - i ); // Calculate the minimum between the largest left value and the remaining k - i
        ans += change * change; // Add the square of the calculated value to ans
        cards [ 25 ].left -= change; // Decrement the left property of the largest element
        i += change - 1; // Adjust the loop counter
    }
    printf ( "%lld", ans ); // Print the result
    return 0; // Return 0 to indicate successful execution
}

