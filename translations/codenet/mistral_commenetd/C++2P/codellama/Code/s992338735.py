#include <iostream>
using namespace std;

# Initialize two integer variables N and S for input and output respectively
N, S = 0, 0

# Start the while loop that runs as long as the user inputs a positive integer N
while ( True):
   # Initialize variables M, m, and addup with default values
   M, m, addup = -1, 1001, 0
   # Initialize i as a loop counter
   i = 0

   # Run the loop N times
   while ( i < N):
      # Read the next integer S from the user input
      S = int(input())
      # Add the current subarray sum S to the total sum addup
      addup += S
      # Update M if the current subarray sum is larger than the current minimum sum
      if ( S > M):
         M = S
      # Update m if the current subarray sum is smaller than the current maximum sum
      if ( S < m):
         m = S
      # Increment the loop counter
      i += 1

   # Calculate and print the average of the differences between the maximum and minimum sums of all subarrays
   print((addup - M - m)/(N-2))
   # Read the next integer N from the user input
   N = int(input())

# End of code
