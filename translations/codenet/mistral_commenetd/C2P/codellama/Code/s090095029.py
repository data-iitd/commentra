
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int main() {
  # Declare variables
  n, m = map(int, input().split())

  # Initialize boolean array r0 with all elements set to false
  r0 = [False] * n

  # Initialize integer array r1 and counter for its size
  r1 = []
  nr1 = 0

  # Process each of the m input pairs
  for i in range(m):
    # Read input values for a and b
    a, b = map(int, input().split())

    # Swap a and b if a is greater than b
    if a > b:
      t = a
      a = b
      b = t

    # If a is equal to 1, set the corresponding element in r0 to true
    if a == 1:
      r0[b - 1] = True

    # If b is equal to n, add its index to r1
    if b == n:
      r1.append(a - 1)
      nr1 += 1

  # Initialize boolean variable res to false
  res = False

  # Check if there exists any pair in r1 whose corresponding element in r0 is true
  for i in range(nr1):
    # If such a pair is found, set res to true
    if r0[r1[i]]:
      res = True

  # Output the result based on the value of res
  print("POSSIBLE" if res else "IMPOSSIBLE")

  # Return 0 to indicate successful execution
  return 0
}

