# <START-OF-CODE>

# Declare variables
n = 0
min = 1000000
max = -1000000
sum = 0

# Read the number of integers to be processed
n = int(input())

# Loop to read n integers
for i in range(n):
    # Read the next integer
    tmp = int(input())
    
    # Update min if the current number is smaller
    if min > tmp: min = tmp
    
    # Update max if the current number is larger
    if max < tmp: max = tmp
    
    # Add the current number to the sum
    sum += tmp

# Print the minimum, maximum, and sum of the numbers
print(min, max, sum)

# 