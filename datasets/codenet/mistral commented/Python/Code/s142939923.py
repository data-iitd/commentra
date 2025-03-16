# Read two integers from the user and assign them to variables a and b
a, b = map(int, input().split())

# Initialize an empty list x
x = []

# Add the sum of a and b to the x list
x.append(a + b)

# Add the difference of a and b to the x list
x.append(a - b)

# Add the product of a and b to the x list
x.append(a * b)

# Find the maximum value in the x list and print it to the console
print(max(x))
