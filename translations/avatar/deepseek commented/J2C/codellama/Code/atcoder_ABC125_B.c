
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 1000

int main ( ) { 
    // Step 1: Read the input value `n` which represents the number of elements.
    int n ; 
    scanf ( "%d" , &n ) ; 
    
    // Step 2: Read the values of `v` (values) and store them in a list `vList`.
    char vStr [ MAX_INPUT_SIZE ] ; 
    scanf ( "%s" , vStr ) ; 
    int vList [ n ] ; 
    int vListIdx = 0 ; 
    char * vStrPtr = strtok ( vStr , " " ) ; 
    while ( vStrPtr != NULL ) { 
        vList [ vListIdx ] = atoi ( vStrPtr ) ; 
        vListIdx ++ ; 
        vStrPtr = strtok ( NULL , " " ) ; 
    } 
    
    // Step 3: Read the values of `c` (costs) and store them in a list `cList`.
    char cStr [ MAX_INPUT_SIZE ] ; 
    scanf ( "%s" , cStr ) ; 
    int cList [ n ] ; 
    int cListIdx = 0 ; 
    char * cStrPtr = strtok ( cStr , " " ) ; 
    while ( cStrPtr != NULL ) { 
        cList [ cListIdx ] = atoi ( cStrPtr ) ; 
        cListIdx ++ ; 
        cStrPtr = strtok ( NULL , " " ) ; 
    } 
    
    // Step 4: Initialize a variable `max` to keep track of the maximum profit.
    int max = 0 ; 
    
    // Step 5: Iterate through the elements, calculate the profit for each element, and update `max` if the profit is positive.
    for ( int i = 0 ; i < n ; i ++ ) { 
        int profit = vList [ i ] - cList [ i ] ; 
        if ( profit > 0 ) { 
            max += profit ; 
        } 
    } 
    
    // Step 6: Print the maximum profit.
    printf ( "%d\n" , max ) ; 
    
    return 0 ; 
}

