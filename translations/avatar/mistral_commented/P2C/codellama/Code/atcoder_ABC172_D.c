#include <stdio.h>

// Function to read a single line from standard input and return it as a string
// with the trailing newline character removed
char *rs ( ) {
    char *s = NULL;
    size_t n = 0;
    getline ( &s , &n , stdin );
    return s;
}

// Function to read a single integer from standard input
int ri ( ) {
    return atoi ( rs ( ) );
}

// Function to read a list of integers from standard input
// Each line of input is assumed to contain space-separated integers
int *ri_ ( ) {
    char *s = rs ( );
    int *a = malloc ( sizeof ( int ) * ( strlen ( s ) + 1 ) );
    int i = 0;
    while ( sscanf ( s , "%d" , &a [ i ] ) == 1 ) {
        i++;
        s = strchr ( s , ' ' );
        if ( s == NULL ) {
            break;
        }
        s++;
    }
    return a;
}

int main ( ) {
    // Read the number of test cases from standard input
    int N = ri ( );

    // Initialize the answer to 0
    int ans = 0;

    // Iterate through all numbers from 1 to N
    for ( int i = 1 ; i <= N ; i++ ) {
        // Calculate the contribution of i to the answer
        // The formula is given by the problem statement
        ans += i * ( N / i ) * ( N / i + 1 ) / 2;
    }

    // Print the answer
    printf ( "%d\n" , ans );

    return 0;
}

