# Declare an integer variable to hold the number of elements
n = int(input())

# Declare an array to hold up to 100 integers
array = [0] * 100

# Input the elements into the array
for i in range(n):
    array[i] = int(input())

# Initialize a variable to hold the sum of products
sum = 0

# Calculate the sum of products of all unique pairs of elements in the array
for i in range(n - 1):
    for j in range(i + 1, n):
        sum += array[i] * array[j] # Add the product of the pair to the sum

# Output the final sum of products
print(sum)

# 