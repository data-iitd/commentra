"""
This program calculates the sum of numbers from 1 to n that are not multiples of 3 and 5.
"""

n = int(input())  # Read the number n from the user
r = 0             # Initialize the sum variable r to 0

"""
Iterate through the numbers from 1 to n
"""
for ii in range(1, n+1):
  """
  Check if the current number ii is not a multiple of both 3 and 5
  """
  if (ii)%3 != 0 and (ii)%5 != 0:
    """
    If the condition is true, add the current number ii to the sum r
    """
    r += ii

"""
Print the final sum of numbers that are not multiples of 3 and 5
"""
print(r)