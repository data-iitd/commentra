#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 100000

int main ( ) {
    int n, i, j, k, l, m, count, flag;
    char str[MAX], str1[MAX], str2[MAX], str3[MAX];
    scanf ( "%d", &n );
    for ( i = 0 ; i < n ; i++ ) {
        scanf ( "%s", str );
        scanf ( "%s", str1 );
        scanf ( "%s", str2 );
        scanf ( "%s", str3 );
        count = 0;
        for ( j = 0 ; j < strlen ( str ) ; j++ ) {
            if ( str[j] == str1[0] ) {
                for ( k = 0 ; k < strlen ( str1 ) ; k++ ) {
                    if ( str[j+k]!= str1[k] ) {
                        break;
                    }
                }
                if ( k == strlen ( str1 ) ) {
                    for ( l = 0 ; l < strlen ( str2 ) ; l++ ) {
                        str[j+l] = str2[l];
                    }
                    count++;
                }
            }
        }
        if ( count == 0 ) {
            for ( m = 0 ; m < strlen ( str3 ) ; m++ ) {
                str[m] = str3[m];
            }
        }
        printf ( "%s\n", str );
    }
    return 0;
}
