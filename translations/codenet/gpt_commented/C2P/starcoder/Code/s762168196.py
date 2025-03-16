# <START-OF-CODE>

# Declare an array to hold up to 10,000 integers
a = [0] * 10000

# Initialize a variable to hold the sum of the integers
sum = 0

# Read the number of integers to be processed
n = int(input())

# Read n integers from input and calculate their sum
for i in range(n):
    a[i] = int(input()) # Read each integer into the array
    sum += a[i]        # Add the integer to the sum

# Initialize min and max with the first element of the array
min = max = a[0]

# Iterate through the array to find the minimum and maximum values
for i in range(1, n):
    if a[i] > max: max = a[i] # Update max if the current element is greater
    if a[i] < min: min = a[i] # Update min if the current element is smaller

# Print the minimum, maximum, and sum of the integers
print(min, max, sum)

# 