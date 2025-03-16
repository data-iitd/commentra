# Initialize variables to store the sum, current number, count of numbers, and min/max values
sum = 0  # To hold the sum of all numbers
n = int(input())  # Read the total number of integers to be processed

# Initialize min and max variables
min = None
max = None

# Loop through each number to read and process
for i in range(n):
    m = int(input())  # Read the current number
    
    # Add the current number to the sum
    sum += m

    # Initialize min and max with the first number read
    if min is None or max is None:
        min = m  # Set min to the first number
        max = m  # Set max to the first number
    else:
        # Update min if the current number is less than the current min
        if min > m:
            min = m  # Update min

        # Update max if the current number is greater than the current max
        if max < m:
            max = m  # Update max

# Print the minimum, maximum, and sum of the numbers
print(min, max, sum)

# <END-OF-CODE>
