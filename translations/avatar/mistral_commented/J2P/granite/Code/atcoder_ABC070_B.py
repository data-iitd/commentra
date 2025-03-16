

import sys

# Read input integers a, b, c, and d
a = int(sys.stdin.readline())
b = int(sys.stdin.readline())
c = int(sys.stdin.readline())
d = int(sys.stdin.readline())

# Check if c is greater than b
if c > b:
  # If yes, print 0 and exit
  print(0)
  sys.exit()

# Check if a is greater than d
elif a > d:
  # If yes, print 0 and exit
  print(0)
  sys.exit()

# Check if a is less than c
elif a < c:
  # If yes, calculate the difference between the smaller and larger of b and d
  difference = min(b, d) - c
  # Print the difference
  print(difference)
  sys.exit()

# If none of the above conditions are true, then a, b, c, and d are in sorted order
else:
  # Create a List of integers a, b, c, and d
  l = [a, b, c, d]

  # Sort the List in ascending order
  l.sort()

  # Calculate the difference between the second and third elements of the List
  difference = l[2] - l[1]

  # Print the difference
  print(difference)

# End of code
