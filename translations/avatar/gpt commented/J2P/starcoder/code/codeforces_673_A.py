
# Importing the necessary packages
import sys

# Reading the number of elements to be processed
n = int(input())

# Initializing an array to store the integer values
a = []
value = 0

# Loop to read 'n' integers from user input and add them to the array
for i in range(n):
    value = int(input())
    a.append(value)

# Variables to hold the result, position of the last valid number, and a flag
result, pos = 0, 0
flag = 0

# Check if the first element is greater than 15
if a[0] > 15:
    result = 15 # If true, set result to 15
else:
    # Loop through the array to find the first gap greater than 15
    for i in range(1, n):
        if a[i] - a[i - 1] > 15:
            pos = i - 1 # Store the position of the last valid number
            flag = 1 # Set flag to indicate a gap was found
            break # Exit the loop as we found the gap
    # If a gap was found, calculate the result based on the last valid number
    if flag == 1:
        result = a[pos] + 15
    else:
        # If no gap was found, set result based on the last number in the list
        result = a[n - 1] + 15

# Ensure the result does not exceed 90
if result > 90:
    result = 90 # Cap the result at 90

# Output the final result
print(result)

# 