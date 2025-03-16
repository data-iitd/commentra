#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ( ) { 
    int n, k, i, ans = 0 ; 
    scanf ( "%d %d" , &n , &k ) ; 
    int a [ n ] ; 
    for ( i = 0 ; i < n ; ++ i ) 
        scanf ( "%d" , &a [ i ] ) ; 
    qsort ( a , n , sizeof ( int ) , cmp ) ; 
    for ( i = 0 ; i < k ; ++ i ) 
        ans += a [ i ] ; 
    printf ( "%d\n" , ans ) ; 
    return 0 ; 
} 

int cmp ( const void * a , const void * b ) { 
    return ( * ( int * ) a - * ( int * ) b ) ; 
} 

