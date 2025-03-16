# Step 1: Include the standard input/output library.
import sys

# Step 2: Define the main function.
def main():
  # Step 3: Declare integer variables A, B, C, D, E, and max.
  A = 0
  B = 0
  C = 0
  D = 0
  E = 0
  max = 0

  # Step 4: Read two integers A and B from the user.
  A = int(sys.stdin.readline())
  B = int(sys.stdin.readline())

  # Step 5: Calculate the sum of A and B, store it in C.
  C = A + B

  # Step 6: Calculate the difference between A and B, store it in D.
  D = A - B

  # Step 7: Calculate the product of A and B, store it in E.
  E = A * B

  # Step 8: Initialize max with the value of C.
  max = C

  # Step 9: Compare max with D and update max if D is greater.
  if max < D:
    max = D

  # Step 10: Compare max with E and update max if E is greater.
  if max < E:
    max = E

  # Step 11: Print the maximum value.
  print(max)

  # Step 12: Return 0 to indicate successful execution.
  return 0

# Step 13: Call the main function.
if __name__ == "__main__":
  main()

# 