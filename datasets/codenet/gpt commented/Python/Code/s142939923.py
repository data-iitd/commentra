# Read two integers from user input and assign them to variables a and b
a, b = map(int, input().split())

# Create a list to store the results of arithmetic operations
x = []

# Calculate the sum of A and B and add it to the list
x.append(a + b)

# Calculate the difference of A and B (A - B) and add it to the list
x.append(a - b)

# Calculate the product of A and B and add it to the list
x.append(a * b)

# Print the maximum value from the list of results
print(max(x))
