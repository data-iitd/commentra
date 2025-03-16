
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MOD 1000000007L
#define N 1000000000L

char *TOKENS[] = { "A" , "C" , "G" , "T" } ;

typedef struct {
  long *memo ;
  int N ;
} Main ;

long calc ( Main *ins ) {
  return dfs ( ins , 0 , "TTT" ) ;
}

int isOK ( char *last4 ) {
  if ( strstr ( last4 , "AGC" ) != NULL ) {
    return 0 ;
  }

  for ( int i = 0 ; i < 3 ; ++ i ) {
    char *vals = malloc ( 4 * sizeof ( char ) ) ;
    strcpy ( vals , last4 ) ;
    vals [ i ] = last4 [ i + 1 ] ;
    vals [ i + 1 ] = last4 [ i ] ;
    char *s = vals ;

    if ( strstr ( s , "AGC" ) != NULL ) {
      return 0 ;
    }
  }

  return 1 ;
}

long dfs ( Main *ins , int current , char *last3 ) {
  if ( ins->memo [ current ] != NULL ) {
    return ins->memo [ current ] ;
  }

  if ( current == ins->N ) {
    return 1 ;
  }

  long result = 0 ;

  for ( int i = 0 ; i < 4 ; ++ i ) {
    if ( isOK ( last3 + TOKENS [ i ] ) ) {
      result = ( result + dfs ( ins , current + 1 , last3 + TOKENS [ i ] ) ) % MOD ;
    }
  }

  ins->memo [ current ] = result ;
  return result ;
}

int main ( ) {
  Main ins = { .N = N , .memo = malloc ( N * sizeof ( long ) ) } ;
  printf ( "%ld\n" , calc ( &ins ) ) ;
  return 0 ;
}

