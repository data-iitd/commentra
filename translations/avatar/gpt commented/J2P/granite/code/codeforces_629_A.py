
import sys

# Read the number of strings to be processed
num = int(input())

# Initialize counters for occurrences of 'C' and the total fine
counter = 0
fine = 0

# Create an empty list to store the input strings
arr = []

# Read 'num' strings from input and add them to the list
for i in range(num):
    s = input()
    arr.append(s)

# Calculate fines based on occurrences of 'C' in each column
for i in range(num):
    for k in range(num):
        # Count occurrences of 'C' in the current column
        if arr[k][i] == 'C':
            counter += 1
    # Update the fine based on the number of 'C's found in this column
    fine += (counter * (counter - 1)) // 2
    # Reset counter for the next column
    counter = 0

# Calculate fines based on occurrences of 'C' in each row
for i in range(num):
    for k in range(num):
        # Count occurrences of 'C' in the current row
        if arr[i][k] == 'C':
            counter += 1
    # Update the fine based on the number of 'C's found in this row
    fine += (counter * (counter - 1)) // 2
    # Reset counter for the next row
    counter = 0

# Output the total fine calculated
print(fine)

