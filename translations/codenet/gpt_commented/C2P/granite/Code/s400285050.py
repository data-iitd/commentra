
# Function 'you' that computes the greatest common divisor (GCD) using the Euclidean algorithm
def you(x, y):
    z = 0
    while True:
        z = x % y
        x = y
        y = z
        if y <= 0:
            break
    return x

# Read two integers from user input
x = int(input("Enter the first integer: "))
y = int(input("Enter the second integer: "))

# Call the 'you' function with the larger and smaller of the two integers
if x >= y:
    z = you(x, y)
else:
    z = you(y, x)

# Print the result returned from the 'you' function
print("The greatest common divisor of", x, "and", y, "is", z)

