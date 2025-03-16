#include <stdio.h>
#include <stdlib.h>

// Define a constant for the modulo value
const int mod = 1000000007;

// Define a constant for the input/output buffer size (1MB)
const int ioBufferSize = 1 * 1024 * 1024;

// Initialize a buffered scanner for reading input
FILE *sc = fopen( "input.txt", "r" );

// Function to read the next string from input
char *next() {
	char *str = (char *) malloc( sizeof( char ) * 100 );
	fscanf( sc, "%s", str );
	return str;
}

// Function to read the next integer from input
int nextInt() {
	int i;
	fscanf( sc, "%d", &i );
	return i;
}

int main() {
	// Read the values of h and n from input
	int h, n = nextInt(), a = 0;

	// Loop to read n integers and accumulate their sum
	for ( int i = 0; i < n; i++ ) {
		a += nextInt();
	}

	// Check if the accumulated sum is less than h
	if ( h > a ) {
		// If h is greater than the sum, print "No"
		printf( "No\n" );
	} else {
		// Otherwise, print "Yes"
		printf( "Yes\n" );
	}

	// Close the input file
	fclose( sc );

	// End of code
	return 0;
}