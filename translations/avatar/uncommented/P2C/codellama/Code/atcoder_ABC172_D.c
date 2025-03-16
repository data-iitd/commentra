#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *rs ( ) {
    char *s = malloc ( 1000000 );
    fgets ( s , 1000000 , stdin );
    return s;
}

int ri ( ) {
    return atoi ( rs ( ) );
}

char **rs_ ( ) {
    char *s = rs ( );
    char **s_ = malloc ( 1000000 );
    int i = 0;
    char *p = strtok ( s , " " );
    while ( p != NULL ) {
        s_[i++] = p;
        p = strtok ( NULL , " " );
    }
    return s_;
}

int *ri_ ( ) {
    char **s_ = rs_ ( );
    int *s = malloc ( 1000000 );
    int i = 0;
    while ( s_[i] != NULL ) {
        s[i] = atoi ( s_[i] );
        i++;
    }
    return s;
}

int main ( ) {
    int N = ri ( );
    int ans = 0;
    for ( int i = 1 ; i <= N ; i++ ) {
        ans += i * ( N / i ) * ( N / i + 1 ) / 2;
    }
    printf ( "%d\n" , ans );
    return 0;
}



