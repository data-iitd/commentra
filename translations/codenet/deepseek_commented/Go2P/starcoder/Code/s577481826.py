
# Python 3

# Read input from stdin
a = int(input())
b = int(input())

# Perform addition of the two integers
ret = a + b

# Check if the result is less than the difference between the two integers
if ret < (a - b):
	ret = a - b

# Check if the updated result is less than the product of the two integers
if ret < (a * b):
	ret = a * b

# Print the final result
print(ret)

