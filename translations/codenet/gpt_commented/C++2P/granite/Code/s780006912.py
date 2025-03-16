
# Read the number of elements from the user
n = int(input())

# Input the elements into the array
array = [int(input()) for _ in range(n)]

# Initialize a variable to hold the sum of products
sum = 0

# Calculate the sum of products of all unique pairs of elements in the array
for i in range(n - 1):
    for j in range(i + 1, n):
        sum += array[i] * array[j] # Add the product of the pair to the sum

# Output the final sum of products
print(sum)

