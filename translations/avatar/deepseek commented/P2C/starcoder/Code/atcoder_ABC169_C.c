
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

int main ( ) {
    // Read two inputs, convert one to integer and the other to scaled integer
    char sa[100], sb[100];
    scanf ( "%s %s", sa, sb );
    int a = atoi ( sa );
    int b = ( int ) ( atof ( sb ) * 100 + 0.1 );
    
    // Perform the calculation and print the result
    printf ( "%d\n", a * b / 100 );
    
    return 0;
}

