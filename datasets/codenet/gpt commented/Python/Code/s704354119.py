# Read the number of elements from user input
n = int(input())

# Read the elements as a list of strings and split them
l = input().split()

# Initialize variables to track the maximum, minimum, and sum of the elements
max = -1e9  # Set initial maximum to a very small number
min = 1e9   # Set initial minimum to a very large number
sum = 0     # Initialize sum to zero

# Iterate through each element in the list
for i in range(n):
    # Convert the current element to an integer and add it to the sum
    sum += int(l[i])
    
    # Update the maximum value if the current element is greater than the current maximum
    if max < int(l[i]):
        max = int(l[i])
    
    # Update the minimum value if the current element is less than the current minimum
    if min > int(l[i]):
        min = int(l[i])

# Print the minimum value, maximum value, and the sum of all elements
print(min, max, sum)
