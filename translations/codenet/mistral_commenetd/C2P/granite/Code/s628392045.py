
# Python code to solve the problem

# Read the number of test cases
n = int(input())

# Initialize variables
h = []
max = -1
flag = 0

# Read and process input
for i in range(n):
  # Read the next integer from standard input and store it in the list h
  h.append(int(input()))

  # Update the maximum height if the current height is greater
  if max < h[i]: max = h[i]

  # Check if the difference between the current height and maximum height is greater than or equal to 2
  if max - h[i] >= 2: flag = 1

# Check the value of the flag and print the appropriate message to the standard output
if flag == 1: print("No")
else: print("Yes")

# End of Python code
