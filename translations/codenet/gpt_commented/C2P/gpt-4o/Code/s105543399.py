# Declare variables
n = 0  # Number of elements
a = 0  # Current number
m = 100000000  # Initialize minimum value to a large number
M = -100000000  # Initialize maximum value to a small number
c = 0  # Cumulative sum of the numbers

# Read the number of elements
n = int(input())

# Loop through each element to read and process
for i in range(n):
    # Read the current number
    a = int(input())
    
    # Update maximum value if the current number is greater
    if a > M:
        M = a
    
    # Update minimum value if the current number is smaller
    if a < m:
        m = a
    
    # Add the current number to the cumulative sum
    c += a

# Print the minimum, maximum, and cumulative sum
print(m, M, c)

# <END-OF-CODE>
