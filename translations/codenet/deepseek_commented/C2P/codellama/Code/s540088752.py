#include <stdio.h>

int main(void) {
   
   # Declare arrays A and B with sizes N+1 and N respectively
   N = int(input())
   A = [int(input()) for i in range(N+1)]
   B = [int(input()) for i in range(N)]
   i = 0
   
   # Initialize the result variable
   ans = 0
   
   # Loop through each index from 0 to N-1
   for i in range(N):
      
      # Site i
      # Check if the current element in A is greater than or equal to the current element in B
      if A[i] >= B[i]:
         # Add the current element in B to ans and subtract it from A
         ans = ans + B[i]
         A[i] = A[i] - B[i]
         # Set the current element in B to 0
         B[i] = 0
      else:
         # Add the current element in A to ans and subtract it from B
         ans = ans + A[i]
         B[i] = B[i] - A[i]
         # Set the current element in A to 0
         A[i] = 0

      # Site i + 1
      # Check if the next element in A is greater than or equal to the current element in B
      if A[i + 1] >= B[i]:
         # Add the current element in B to ans and subtract it from A
         ans = ans + B[i]
         A[i + 1] = A[i + 1] - B[i]
         # Set the current element in B to 0
         B[i] = 0
      else:
         # Add the current element in A to ans and subtract it from B
         ans = ans + A[i + 1]
         B[i] = B[i] - A[i + 1]
         # Set the current element in A to 0
         A[i + 1] = 0
   # Print the final result
   print(ans)
   
   return 0
   
}

