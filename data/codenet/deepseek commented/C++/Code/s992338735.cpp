#include <iostream> // Include necessary headers and namespaces
using namespace std;

int N, S; // Declare global variables

int main(){ // Start the main function
   while ( cin >> N && N>0){ // Read the number of elements (N)
      int M, m, addup, i; // Initialize variables for maximum, minimum, sum, and index
      M = -1;
      m = 1001;
      addup = 0;
      for ( i = 0; i<N; i++){ // Loop through each element and update the maximum, minimum, and sum
         cin >> S;
         addup += S;
         if ( S > M) M = S;
         if ( S < m) m = S;
      }
      cout << (addup - M - m)/(N-2)  << endl; // Calculate the average of the remaining numbers
   }
} // End the loop and main function
