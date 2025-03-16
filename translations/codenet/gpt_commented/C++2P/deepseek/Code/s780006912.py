# Read the number of elements from the user
n = int(input())

# Input the elements into the array
array = list(map(int, input().split()))

# Initialize a variable to hold the sum of products
sum_of_products = 0

# Calculate the sum of products of all unique pairs of elements in the array
for i in range(n):
    for j in range(i + 1, n):
        sum_of_products += array[i] * array[j]  # Add the product of the pair to the sum

# Output the final sum of products
print(sum_of_products)

# End-of-code
