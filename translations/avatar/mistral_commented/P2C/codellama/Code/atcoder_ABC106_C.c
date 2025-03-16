
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

// Defining constants
#define INF 100000000
#define EPS 1.0 / 100000000
#define MOD 1000000007

// Defining direction vectors
int dd[8][2] = { { -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, -1 }, { -1, 1 }, { 1, 1 }, { 1, -1 } };

// Function to read a list of integers from standard input
int* LI( int* n ) {
    *n = 0;
    char* line = NULL;
    size_t len = 0;
    getline( &line, &len, stdin );
    char* token = strtok( line, " " );
    int* arr = (int*)malloc( sizeof( int ) * strlen( line ) );
    while( token != NULL ) {
        arr[*n] = atoi( token );
        token = strtok( NULL, " " );
        *n += 1;
    }
    return arr;
}

// Function to read a list of integers from standard input, subtracting 1 from each element
int* LI_( int* n ) {
    *n = 0;
    char* line = NULL;
    size_t len = 0;
    getline( &line, &len, stdin );
    char* token = strtok( line, " " );
    int* arr = (int*)malloc( sizeof( int ) * strlen( line ) );
    while( token != NULL ) {
        arr[*n] = atoi( token ) - 1;
        token = strtok( NULL, " " );
        *n += 1;
    }
    return arr;
}

// Function to read a list of floats from standard input
float* LF( int* n ) {
    *n = 0;
    char* line = NULL;
    size_t len = 0;
    getline( &line, &len, stdin );
    char* token = strtok( line, " " );
    float* arr = (float*)malloc( sizeof( float ) * strlen( line ) );
    while( token != NULL ) {
        arr[*n] = atof( token );
        token = strtok( NULL, " " );
        *n += 1;
    }
    return arr;
}

// Function to read a single line from standard input as a list of strings
char** LS( int* n ) {
    *n = 0;
    char* line = NULL;
    size_t len = 0;
    getline( &line, &len, stdin );
    char* token = strtok( line, " " );
    char** arr = (char**)malloc( sizeof( char* ) * strlen( line ) );
    while( token != NULL ) {
        arr[*n] = token;
        token = strtok( NULL, " " );
        *n += 1;
    }
    return arr;
}

// Function to read a single integer from standard input
int I( ) {
    int x = 0;
    scanf( "%d", &x );
    return x;
}

// Function to read a single float from standard input
float F( ) {
    float x = 0;
    scanf( "%f", &x );
    return x;
}

// Function to read a single string from standard input
char* S( ) {
    char* s = (char*)malloc( sizeof( char ) * 1000 );
    scanf( "%s", s );
    return s;
}

// Function to print a string with a newline character at the end
void pf( char* s ) {
    printf( "%s\n", s );
}

// Main function
int main( ) {
    // Reading input string and number of occurrences of '1' required
    char* s = S( );
    int k = I( );

    // Finding the length of the substring consisting only of '1's
    int l = 0;
    for( int i = 0; i < strlen( s ); i++ ) {
        if( s[i] != '1' ) {
            // If the length of the substring is greater than or equal to the required number of occurrences, return 1
            if( l >= k ) {
                pf( "1" );
                return 1;
            }
            break;
        }
        l += 1;
    }

    // If the length of the substring is less than the required number of occurrences, return the character after the substring
    pf( s[l] );
    return 0;
}

