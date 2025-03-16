
# Read the total number of integers to be processed
n = int(input())

# Initialize variables to store the sum, current number, count of numbers, and min/max values
sum = 0 # To hold the sum of all numbers
min = None # Initialize min with None
max = None # Initialize max with None

# Loop through each number to read and process
for i in range(n):
    # Read the current number
    m = int(input())
    
    # Add the current number to the sum
    sum += m

    # Update min if the current number is less than the current min
    if min is None or m < min:
        min = m # Update min

    # Update max if the current number is greater than the current max
    if max is None or m > max:
        max = m # Update max

# Print the minimum, maximum, and sum of the numbers
print(min, max, sum)

