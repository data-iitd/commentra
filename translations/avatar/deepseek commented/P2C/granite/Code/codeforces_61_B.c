
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// Function to check if a given pair of indices (i, j) is within the bounds of a grid with dimensions n by m
int valid ( int i, int j, int n, int m ) {
    if ( i < n && i >= 0 && j >= 0 && j < m ) return 1;
    return 0;
}

// Function to calculate the sum of an arithmetic series from i to n
int sumn ( int i, int n ) {
    return ( n - i ) * ( i + n ) / 2;
}

// Function to solve a quadratic equation of the form ax^2 + bx + c = 0
double sqfun ( double a, double b, double c ) {
    return ( - b + sqrt ( b * b - 4 * a * c ) ) / 2 * a;
}

// Function to read a single or multiple integer values from input
int value ( ) {
    int x;
    scanf ( "%d", &x );
    return x;
}

// Function to read a single or multiple integer values from standard input
int values ( ) {
    int x;
    scanf ( "%d", &x );
    return x;
}

// Function to read a list of integers from input
int* inlst ( ) {
    int n = value ( );
    int* a = ( int* ) malloc ( n * sizeof ( int ) );
    for ( int i = 0 ; i < n ; i ++ ) scanf ( "%d", &a[i] );
    return a;
}

// Function to read a list of integers from standard input
int* inlsts ( ) {
    int n = value ( );
    int* a = ( int* ) malloc ( n * sizeof ( int ) );
    for ( int i = 0 ; i < n ; i ++ ) scanf ( "%d", &a[i] );
    return a;
}

// Function to read a single integer from input
int inp ( ) {
    int x;
    scanf ( "%d", &x );
    return x;
}

// Function to read a single integer from standard input
int inps ( ) {
    int x;
    scanf ( "%d", &x );
    return x;
}

// Function to read a string from input
char* instr ( ) {
    char* s = ( char* ) malloc ( 100 * sizeof ( char ) );
    fgets ( s, 100, stdin );
    s[strlen ( s ) - 1] = '\0';
    return s;
}

// Function to split a string into a list of words
char** stlst ( ) {
    char* s = instr ( );
    char** a = ( char** ) malloc ( 100 * sizeof ( char* ) );
    int n = 0;
    char* t = s;
    while ( *t!= '\0' ) {
        if ( *t =='' || *t == '-' || *t == ';' || *t == '_' ) {
            *t = '\0';
            t ++;
        } else {
            a[n] = t;
            n ++;
            t ++;
        }
    }
    return a;
}

// Function to sanitize a string by converting it to lowercase and removing certain characters
char* f ( char* s ) {
    char* r = ( char* ) malloc ( 100 * sizeof ( char ) );
    int k = 0;
    for ( int i = 0 ; s[i]!= '\0' ; i ++ ) {
        if ( s[i]!= '-' && s[i]!= ';' && s[i]!= '_' ) {
            r[k] = tolower ( s[i] );
            k ++;
        }
    }
    r[k] = '\0';
    return r;
}

// Main logic of the program
void solve ( ) {
    char* l[3];
    for ( int i = 0 ; i < 3 ; i ++ ) l[i] = f ( instr ( ) );
    char** t = ( char** ) malloc ( 6 * sizeof ( char* ) );
    int k = 0;
    for ( int i = 0 ; i < 3 ; i ++ ) {
        for ( int j = 0 ; j < 3 ; j ++ ) {
            if ( i!= j ) {
                t[k] = ( char* ) malloc ( 100 * sizeof ( char ) );
                strcpy ( t[k], l[i] );
                strcat ( t[k], l[j] );
                k ++;
            }
        }
    }
    for ( int i = 0 ; i < 3 ; i ++ ) {
        for ( int j = 0 ; j < 3 ; j ++ ) {
            if ( i!= j ) {
                t[k] = ( char* ) malloc ( 100 * sizeof ( char ) );
                strcpy ( t[k], l[j] );
                strcat ( t[k], l[i] );
                k ++;
            }
        }
    }
    for ( int i = 0 ; i < k ; i ++ ) free ( t[i] );
    free ( t );
    int n = inp ( );
    for ( int i = 0 ; i < n ; i ++ ) {
        char* s = f ( instr ( ) );
        int flag = 0;
        for ( int j = 0 ; j < k ; j ++ ) {
            if ( strcmp ( s, t[j] ) == 0 ) {
                flag = 1;
                break;
            }
        }
        if ( flag ) printf ( "ACC\n" );
        else printf ( "WA\n" );
        free ( s );
    }
}

int main ( ) {
    solve ( );
    return 0;
}

