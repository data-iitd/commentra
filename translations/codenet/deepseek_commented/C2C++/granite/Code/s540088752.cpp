
#include <iostream>

int main() {
   
   // Read the size of the arrays
   int N;
   std::cin >> N;
   
   // Declare arrays A and B with sizes N+1 and N respectively
   int A[N+1];
   int B[N];
   int i;
   
   // Read N+1 integers into array A
   for (i = 0; i < N + 1; i++) {
      std::cin >> A[i];
   }
   
   // Read N integers into array B
   for (i = 0; i < N; i++) {
      std::cin >> B[i];
   }
   
   // Initialize the result variable
   long ans = 0;
   
   // Loop through each index from 0 to N-1
   for (i = 0; i < N; i++) {
      
      // Site i
      // Check if the current element in A is greater than or equal to the current element in B
      if (A[i] >= B[i]) {
         // Add the current element in B to ans and subtract it from A
         ans = ans + B[i];
         A[i] = A[i] - B[i];
         // Set the current element in B to 0
         B[i] = 0;
      }
      else {
         // Add the current element in A to ans and subtract it from B
         ans = ans + A[i];
         B[i] = B[i] - A[i];
         // Set the current element in A to 0
         A[i] = 0;
      }

      // Site i + 1
      // Check if the next element in A is greater than or equal to the current element in B
      if (A[i + 1] >= B[i]) {
         // Add the current element in B to ans and subtract it from A
         ans = ans + B[i];
         A[i + 1] = A[i + 1] - B[i];
         // Set the current element in B to 0
         B[i] = 0;
      }
      else {
         // Add the current element in A to ans and subtract it from B
         ans = ans + A[i + 1];
         B[i] = B[i] - A[i + 1];
         // Set the current element in A to 0
         A[i + 1] = 0;
      }
   }
   
   // Print the final result
   std::cout << ans << std::endl;
   
   return 0;
   
}
