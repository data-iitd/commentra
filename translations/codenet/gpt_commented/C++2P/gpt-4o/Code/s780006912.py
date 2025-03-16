# Declare an integer variable to hold the number of elements
n = int(input())

# Declare a list to hold up to 100 integers
array = []

# Input the elements into the list
for i in range(n):
    array.append(int(input()))

# Initialize a variable to hold the sum of products
sum_products = 0

# Calculate the sum of products of all unique pairs of elements in the list
for i in range(n - 1):
    for j in range(i + 1, n):
        sum_products += array[i] * array[j]  # Add the product of the pair to the sum

# Output the final sum of products
print(sum_products)

# Indicate that the program ended successfully
# <END-OF-CODE>
