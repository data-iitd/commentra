# Include the standard input/output library
import sys

# Read input values for A and B
A = int(sys.stdin.readline())
B = int(sys.stdin.readline())

# Loop through numbers 1 to 3 to check if the product of A, B, and i is odd
for i in range(1, 4):
  if((A*B*i)%2 == 1):  # Check if the product is odd
    print("Yes")  # Print "Yes" if an odd product was found
    break  # Break out of the loop
else:
  print("No")  # Print "No" if no odd product was found

# 