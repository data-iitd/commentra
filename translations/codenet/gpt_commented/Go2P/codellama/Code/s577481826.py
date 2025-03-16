
# Initialize a new scanner to read input from standard input
sc = input()

# Function to read a line of input and return it as a string
def read():
    return sc.split()

# Read two integers from input and convert them from string to int
a = int(read()[0]) # Read first integer
b = int(read()[1]) # Read second integer

# Initialize ret with the sum of a and b
ret = a + b

# Check if ret is less than the difference of a and b
if ret < (a - b):
    ret = a - b # Update ret to the difference if it's smaller

# Check if ret is less than the product of a and b
if ret < (a * b):
    ret = a * b # Update ret to the product if it's smaller

# Print the final result
print(ret)

