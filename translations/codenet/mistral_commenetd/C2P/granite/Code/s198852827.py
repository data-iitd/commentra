

# Python code to translate the given C code

# Define a function to calculate the absolute value of a number
def ABS(x):
  if x < 0:
    return -x
  else:
    return x

# Read the number of test cases
N = int(input())

# Initialize variables to store the current test case data and previous coordinates
nx = 0
ny = 0
nt = 0

# Loop through each test case
for i in range(N):
  # Read the current test case data (t, x, y)
  t, x, y = map(int, input().split())

  # Calculate the temporary variable 'tmp' to check the distance between the current and previous coordinates
  tmp = t - nt - (ABS(x - nx) + ABS(y - ny))

  # Check if the current test case satisfies the condition
  if tmp < 0 or tmp % 2!= 0:
    # If the condition is not satisfied, print 'No' and exit the program
    print("No")
    break

  # Update the previous coordinates for the next iteration
  nx = x
  ny = y
  nt = t
else:
  # If all the test cases satisfy the condition, print 'Yes'
  print("Yes")

# End of Python code
