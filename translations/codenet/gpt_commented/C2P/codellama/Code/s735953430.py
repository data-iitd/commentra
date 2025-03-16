#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main()
{
  # Declare variables for minimum index and minimum difference
  i_min, min = 0, 1000
  i, j, k = 0, 0, 0
  X, N = 0, 0

  # Read the values of X and N from user input
  scanf("%d %d", &X, &N)

  # If N is 0, print X and exit the program
  if N == 0:
    printf("%d\n", X)
    exit(0)

  # Initialize arrays to hold positive and negative values
  plus = [0] * 256
  minus = [0] * 256

  # Fill the plus array with indices and minus array with negative indices
  for i in range(256):
    plus[i] = i
    minus[i] = (-1 * i)

  # Read N values and set corresponding indices in the plus array to 0
  for i in range(N):
    scanf("%d", &j)
    plus[j] = 0 # Mark the value as unavailable

  # Initialize minimum index and minimum difference
  i_min = 0
  min = 1000

  # Iterate through the plus array in reverse order to find the closest value to X
  for i in range(255, -1, -1):
    # Skip indices that are marked as unavailable (0) and are greater than 0
    if plus[i] == 0 and i > 0:
      continue

    # Calculate the difference between X and the current value in the plus array
    k = X - plus[i]
    if k < 0: 
      k *= -1 # Take the absolute value of the difference

    # Update minimum difference and index if a closer value is found
    if k <= min:
      min = k
      i_min = i # Store the index of the closest value

  # Print the index of the closest value found
  printf("%d\n", i_min)

  return 0
}

