# Import the sys and collections module
import sys
import collections

# Define the main function
def main():
  # Read the first integer from the input
  n = int(input())

  # Read the second integer array from the input
  s = list(map(int, input().split()))

  # Initialize a boolean list of size n
  u = [False]*n

  # Initialize two integer variables m and f
  m, f = 0, 0

  # Iterate through all the subarrays of size c+1, where c ranges from 1 to n-2
  for c in range(1, n-1):
    # Initialize a variable f to 0
    f = 0

    # Iterate through all the subarrays of size c+1, where k ranges from 0 to n-1-c*c
    for k in range(0, n-1-k*c):
      # Set the boolean value of the current index to true
      u[k*c] = True

      # Check if the boolean value of the last index of the current subarray is already set to true
      # If it is, break the inner loop as we don't need to check further
      if u[n-1-k*c]: break

      # Calculate the sum of the current and previous subarrays
      f += s[n-1-k*c] + s[k*c]

      # Update the value of m if the current sum is greater than the previous maximum sum
      if m < f: m = f

      # Set all the boolean values of the current subarray to false
    # Iterate through all the indices of the current subarray and set their boolean values to false
    for k in range(0, n-1-k*c): u[k*c] = False
  # Print the maximum sum
  print(m)

# Define the main function ends here

# Define the Input class and its methods for reading input
class Input:
  def __init__(self):
    self.num_test_cases = 0
    self.test_cases = []

  def __iter__(self):
    return self

  def __next__(self):
    if self.num_test_cases == 0:
      self.num_test_cases = int(input())
      self.test_cases = [list(map(int, input().split())) for i in range(self.num_test_cases)]
      return self.test_cases[self.num_test_cases - 1]
    elif self.num_test_cases > 0:
      self.num_test_cases -= 1
      return self.test_cases[self.num_test_cases]
    else:
      raise StopIteration

# Define the Input class and its methods for reading input ends here

# Define the main function
if __name__ == '__main__':
  # Read the input
  input = Input()

  # Read the first integer from the input
  n = next(input)

  # Read the second integer array from the input
  s = next(input)

  # Initialize a boolean list of size n
  u = [False]*n

  # Initialize two integer variables m and f
  m, f = 0, 0

  # Iterate through all the subarrays of size c+1, where c ranges from 1 to n-2
  for c in range(1, n-1):
    # Initialize a variable f to 0
    f = 0

    # Iterate through all the subarrays of size c+1, where k ranges from 0 to n-1-c*c
    for k in range(0, n-1-k*c):
      # Set the boolean value of the current index to true
      u[k*c] = True

      # Check if the boolean value of the last index of the current subarray is already set to true
      # If it is, break the inner loop as we don't need to check further
      if u[n-1-k*c]: break

      # Calculate the sum of the current and previous subarrays
      f += s[n-1-k*c] + s[k*c]

      # Update the value of m if the current sum is greater than the previous maximum sum
      if m < f: m = f

      # Set all the boolean values of the current subarray to false
    # Iterate through all the indices of the current subarray and set their boolean values to false
    for k in range(0, n-1-k*c): u[k*c] = False
  # Print the maximum sum
  print(m)

# Define the main function ends here

