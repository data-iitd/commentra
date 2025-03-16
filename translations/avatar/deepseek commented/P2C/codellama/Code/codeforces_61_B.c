#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

// Function to check if a given pair of indices (i, j) is within the bounds of a grid with dimensions n by m
bool valid ( int i , int j , int n , int m ) {
    if ( i < n && i >= 0 && j >= 0 && j < m ) return true;
    return false;
}

// Function to calculate the sum of an arithmetic series from i to n
int sumn ( int i , int n ) {
    return ( n - i ) * ( i + n ) / 2;
}

// Function to solve a quadratic equation of the form ax^2 + bx + c = 0
double sqfun ( double a , double b , double c ) {
    return ( - b + sqrt ( b * b - 4 * a * c ) ) / 2 * a;
}

// Function to read a single or multiple integer values from input
int value ( ) {
    int i , j;
    scanf ( "%d %d" , &i , &j );
    return i * j;
}

// Function to read a single or multiple integer values from standard input
int values ( ) {
    int i , j;
    scanf ( "%d %d" , &i , &j );
    return i * j;
}

// Function to read a list of integers from input
int inlst ( ) {
    int i , n;
    scanf ( "%d" , &n );
    int l[n];
    for ( i = 0 ; i < n ; i++ ) scanf ( "%d" , &l[i] );
    return l[n];
}

// Function to read a list of integers from standard input
int inlsts ( ) {
    int i , n;
    scanf ( "%d" , &n );
    int l[n];
    for ( i = 0 ; i < n ; i++ ) scanf ( "%d" , &l[i] );
    return l[n];
}

// Function to read a single integer from input
int inp ( ) {
    int i;
    scanf ( "%d" , &i );
    return i;
}

// Function to read a single integer from standard input
int inps ( ) {
    int i;
    scanf ( "%d" , &i );
    return i;
}

// Function to read a string from input
char *instr ( ) {
    char *s = ( char * ) malloc ( 1000000 * sizeof ( char ) );
    scanf ( "%s" , s );
    return s;
}

// Function to split a string into a list of words
char **stlst ( ) {
    char *s = ( char * ) malloc ( 1000000 * sizeof ( char ) );
    scanf ( "%s" , s );
    char *t = strtok ( s , " " );
    int n = 0;
    while ( t != NULL ) {
        n++;
        t = strtok ( NULL , " " );
    }
    char **l = ( char ** ) malloc ( n * sizeof ( char * ) );
    t = strtok ( s , " " );
    for ( int i = 0 ; i < n ; i++ ) {
        l[i] = ( char * ) malloc ( 1000000 * sizeof ( char ) );
        strcpy ( l[i] , t );
        t = strtok ( NULL , " " );
    }
    return l;
}

// Function to sanitize a string by converting it to lowercase and removing certain characters
char *f ( char *s ) {
    char *r = ( char * ) malloc ( 1000000 * sizeof ( char ) );
    int i , j = 0;
    for ( i = 0 ; i < strlen ( s ) ; i++ ) {
        if ( s[i] != '-' && s[i] != ';' && s[i] != '_' ) r[j++] = tolower ( s[i] );
    }
    r[j] = '\0';
    return r;
}

// Main logic of the program
void solve ( ) {
    int i , j , n , m;
    char **l = stlst ( );
    char **t = ( char ** ) malloc ( 6 * sizeof ( char * ) );
    for ( i = 0 ; i < 6 ; i++ ) t[i] = ( char * ) malloc ( 1000000 * sizeof ( char ) );
    for ( i = 0 ; i < 6 ; i++ ) strcpy ( t[i] , l[i] );
    for ( i = 0 ; i < 6 ; i++ ) {
        for ( j = 0 ; j < 6 ; j++ ) {
            if ( i != j ) {
                if ( strcmp ( t[i] , t[j] ) == 0 ) {
                    printf ( "ACC\n" );
                    return;
                }
            }
        }
    }
    for ( i = 0 ; i < 6 ; i++ ) {
        for ( j = 0 ; j < 6 ; j++ ) {
            if ( i != j ) {
                if ( strcmp ( t[i] , t[j] ) == 0 ) {
                    printf ( "ACC\n" );
                    return;
                }
            }
        }
    }
    printf ( "WA\n" );
}

int main ( ) {
    solve ( );
    return 0;
}

