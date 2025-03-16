
#include <stdio.h>

int main(){
   int N, S;
   while ( scanf("%d", &N) == 1 && N>0){
      int M = -1;
      int m = 1001;
      int addup = 0;
      int i;
      for ( i = 0; i<N; i++){
         scanf("%d", &S);
         addup += S;
         if ( S > M) M = S;
         if ( S < m) m = S;
      }
      printf("%d\n", (addup - M - m)/(N-2));
   }
}
