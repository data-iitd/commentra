
#include <stdio.h>
#include <stdlib.h>

int cmpfunc ( const void * a, const void * b ) {
   return ( *(int*)a - *(int*)b );
}

int main() {
   int N;
   scanf ( "%d", &N );
   int A[ N ];
   for ( int i = 0 ; i < N ; i ++ ) {
      scanf ( "%d", &A[ i ] );
   }
   qsort ( A, N, sizeof ( int ), cmpfunc );
   for ( int i = 0 ; i < N - 1 ; i ++ ) {
      printf ( "%d ", A[ i ] );
   }
   printf ( "%d\n", A[ N - 1 ] );
   return 0;
}
