
#include <iostream>  // Step 1: Include the standard input/output library.

int main(void) {  // Step 2: Define the main function.
  int A, B, C, D, E, max;  // Step 3: Declare integer variables A, B, C, D, E, and max.

  std::cin >> A >> B;  // Step 4: Read two integers A and B from the user.

  C = A + B;  // Step 5: Calculate the sum of A and B, store it in C.
  D = A - B;  // Step 6: Calculate the difference between A and B, store it in D.
  E = A * B;  // Step 7: Calculate the product of A and B, store it in E.

  max = C;  // Step 8: Initialize max with the value of C.

  if (max < D) {  // Step 9: Compare max with D and update max if D is greater.
    max = D;
  }
  if (max < E) {  // Step 10: Compare max with E and update max if E is greater.
    max = E;
  }

  std::cout << max << std::endl;  // Step 11: Print the maximum value.
  return 0;  // Step 12: Return 0 to indicate successful execution.
}
