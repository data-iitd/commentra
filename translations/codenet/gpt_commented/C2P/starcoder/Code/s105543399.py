# <START-OF-CODE>

# Declare variables
n, a, m, M, c, b, i = 0, 0, 0, 0, 0, 0, 0

# Initialize cumulative sum and set initial min and max values
c = 0 # Cumulative sum of the numbers
m = 100000000 # Initialize minimum value to a large number
M = -100000000 # Initialize maximum value to a small number

# Read the number of elements
n = int(input())

# Loop through each element to read and process
for i in range(1, n+1):
  # Read the current number
  a = int(input())
  
  # Update maximum value if the current number is greater
  if a > M:
    M = a
  
  # Update minimum value if the current number is smaller
  if a < m:
    m = a
  
  # Add the current number to the cumulative sum
  c = c + a

# Print the minimum, maximum, and cumulative sum
print(m, M, c)

# 