#include <stdio.h>

int main():
  # Declare two integer variables K and X
  K, X = int(), int()

  # Read two integers from standard input: K and X
  scanf("%d %d", &K, &X)

  # Loop from (X - K + 1) to (X + K - 1)
  for i in range(X - K + 1, X + K):
    # Print the current value of i
    print(i, end=" ")

  # Print a newline character after the loop completes
  print()

  # Return 0 to indicate successful completion of the program
  return 0

