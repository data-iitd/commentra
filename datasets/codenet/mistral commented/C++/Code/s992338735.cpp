#include <iostream>
using namespace std;

// Define two integer variables N and S for input and output respectively
int N, S;

int main(){
   // Start the while loop that runs as long as the user inputs a positive integer N
   while ( cin >> N && N>0){
      // Initialize variables M, m, and addup with default values
      int M = -1; // Initialize M as an invalid value to represent the minimum sum of subarrays
      int m = 1001; // Initialize m as a large value to represent the maximum sum of subarrays
      int addup = 0; // Initialize addup as a variable to store the sum of all subarrays
      int i; // Initialize i as a loop counter

      // Run the loop N times
      for ( i = 0; i<N; i++){
         // Read the next integer S from the user input
         cin >> S;
         // Add the current subarray sum S to the total sum addup
         addup += S;
         // Update M if the current subarray sum is larger than the current minimum sum
         if ( S > M) M = S;
         // Update m if the current subarray sum is smaller than the current maximum sum
         if ( S < m) m = S;
      }

      // Calculate and print the average of the differences between the maximum and minimum sums of all subarrays
      cout << (addup - M - m)/(N-2)  << endl;
   }
}
