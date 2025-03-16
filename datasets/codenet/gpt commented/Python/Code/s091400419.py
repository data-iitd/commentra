# Read two integers from user input and unpack them into variables a and b
a, b = map(int, input().split())

# Create a list containing the results of three arithmetic operations: 
# addition, subtraction, and multiplication of a and b
lst = [a + b, a - b, a * b]

# Print the maximum value from the list of results
print(max(lst))
