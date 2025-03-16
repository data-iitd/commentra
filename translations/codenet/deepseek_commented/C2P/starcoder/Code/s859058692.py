# <START-OF-CODE>

# Read the number of inputs
n = int(input())

# Declare and initialize the sum variable
sum = 0

# Declare variables for the number of inputs, current input, loop index, min, and max
m = 0
i = 0
min = 0
max = 0

# Loop through each input
for i in range(n):
    m = int(input()) # Read the current input
    sum += m # Update the sum with the current input

    # Check if it's the first input to set initial min and max values
    if i == 0:
        min = m
        max = m

    # Update the min value if the current input is smaller
    if min > m:
        min = m

    # Update the max value if the current input is larger
    if max < m:
        max = m

# Output the minimum, maximum, and sum of the inputs
print(min, max, sum)

# 