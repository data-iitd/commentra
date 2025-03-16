#include <stdio.h> // Include necessary headers and namespaces

int N, S; // Declare global variables

int main(){ // Start the main function
   while ( scanf("%d", &N) == 1 && N>0){ // Read the number of elements (N)
      int M, m, addup, i; // Initialize variables for maximum, minimum, sum, and index
      M = -1;
      m = 1001;
      addup = 0;
      for ( i = 0; i<N; i++){ // Loop through each element and update the maximum, minimum, and sum
         scanf("%d", &S);
         addup += S;
         if ( S > M) M = S;
         if ( S < m) m = S;
      }
      printf("%d\n", (addup - M - m)/(N-2) ); // Calculate the average of the remaining numbers
   }
} // End the loop and main function

