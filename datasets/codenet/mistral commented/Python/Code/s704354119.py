# Take the number of elements in the list as input
n = int(input())

# Read the list elements as strings and split them using space as delimiter
l = input().split()

# Initialize variables for maximum, minimum and sum of list elements
max = -1e9  # Initialize max to a very small negative number
min = 1e9  # Initialize min to a very large positive number
sum = 0   # Initialize sum to zero

# Iterate through each element in the list
for i in range(n):
    # Add the current element to the sum
    sum += int(l[i])
    
    # Update max if the current element is greater
    if max < int(l[i]):
        max = int(l[i])
    
    # Update min if the current element is smaller
    if min > int(l[i]):
        min = int(l[i])

# Print the minimum, maximum and sum of list elements
print(min, max, sum)
