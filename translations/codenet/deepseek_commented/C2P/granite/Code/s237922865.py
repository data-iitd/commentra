
import sys

n = int(input())  # Read the integer n from standard input.

cnt4 = 0  # Initialize the counter for multiples of 4.
cnt2 = 0  # Initialize the counter for multiples of 2.

# Read n integers from standard input and update the counters.
for i in range(n):
  wk = int(input())
  if wk % 4 == 0:  # Check if the integer is a multiple of 4.
    cnt4 += 1
  elif wk % 2 == 0:  # Check if the integer is a multiple of 2 but not 4.
    cnt2 += 1

# Check if the sum of multiples of 4 and multiples of 2 (divided by 2) is greater than or equal to n/2.
if cnt4 + cnt2 // 2 >= n // 2:
  print("Yes")  # Print "Yes" if the condition is met.
else:
  print("No")  # Print "No" otherwise.

