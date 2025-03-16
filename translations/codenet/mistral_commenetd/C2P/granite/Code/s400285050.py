
# Python code to calculate the greatest common divisor (GCD) of two numbers

# Function to calculate the greatest common divisor (GCD) of two numbers
def you(x, y):
    # Repeat the following steps until y becomes zero
    while y!= 0:
        # Calculate the remainder of x divided by y and store it in z
        z = x % y

        # Update the values of x and y
        x = y
        y = z

    # Return the final value of x, which is the greatest common divisor
    return x

# Read two integers from the user using input()
x = int(input("Enter the first integer: "))
y = int(input("Enter the second integer: "))

# Determine which number is greater and call the you() function with the appropriate arguments
if x >= y:
    z = you(x, y) # Call the you() function with x and y as arguments
else:
    z = you(y, x) # Call the you() function with y and x as arguments

# Print the result (the greatest common divisor) to the console
print("The greatest common divisor of", x, "and", y, "is:", z)

