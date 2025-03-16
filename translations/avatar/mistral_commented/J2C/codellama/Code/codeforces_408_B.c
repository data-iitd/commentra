
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000000

int main ( ) {
    char s1[MAX] , s2[MAX] ; // Declare two strings
    int n1 , n2 ; // Declare two integers
    int i , j ; // Declare two integers
    int m1[26] , m2[26] ; // Declare two arrays of integers
    int ans = 0 ; // Declare an integer
    int x1 , x2 ; // Declare two integers
    int flag = 0 ; // Declare an integer

    scanf ( "%s" , s1 ) ; // Read the first string from the input
    scanf ( "%s" , s2 ) ; // Read the second string from the input

    n1 = strlen ( s1 ) ; // Get the length of the first string
    n2 = strlen ( s2 ) ; // Get the length of the second string

    for ( i = 0 ; i < 26 ; i++ ) { // Initialize the arrays of integers
        m1[i] = 0 ;
        m2[i] = 0 ;
    }

    for ( i = 0 ; i < n1 ; i++ ) { // Iterate through each character in the first string
        m1[s1[i] - 'a']++ ; // Increment the count of the character in the first string
    }

    for ( i = 0 ; i < n2 ; i++ ) { // Iterate through each character in the second string
        m2[s2[i] - 'a']++ ; // Increment the count of the character in the second string
    }

    for ( i = 0 ; i < 26 ; i++ ) { // Iterate through each character in the second string
        x1 = m1[i] ; // Get the count of the character in the first string
        x2 = m2[i] ; // Get the count of the character in the second string
        x1 = x1 < x2 ? x1 : x2 ; // Take the minimum count
        ans += x1 ; // Add the minimum count to the answer
    }

    printf ( "%d\n" , ans ) ; // Print the answer

    return 0 ; // Return 0
}

