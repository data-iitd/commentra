
import math

# Input an integer N
N = int(input())

# Calculate the integer square root of N
sqN = int(math.sqrt(N))

# Iterate through a range based on the square root of N
for i in range(sqN):
  # Check if N is divisible by the current value
  if N % (sqN-i) == 0:
    # Calculate and print the specific expression
    print(int(N/(sqN-i) + sqN-i) - 2)
    # Break the loop after printing the result
    break

