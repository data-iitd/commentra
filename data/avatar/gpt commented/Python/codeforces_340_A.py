# Function to compute the Greatest Common Divisor (GCD) of two numbers
def G(a, b):
    # Continue looping until b becomes 0
    while a % b != 0:
        # Update a and b using the Euclidean algorithm
        a, b = b, a % b
    # Return the GCD
    return b

# Function to compute the Least Common Multiple (LCM) of two numbers
def L(a, b):
    # Calculate LCM using the relationship between GCD and LCM
    return a * b // G(a, b)

# Read input values and split them into a list
l = input().split(' ')

# Convert the input strings to integers
x, y, a, b = int(l[0]), int(l[1]), int(l[2]), int(l[3])

# Calculate the LCM of x and y
lcm = L(x, y)

# Calculate and print the count of multiples of LCM in the range [a, b]
print(b // lcm - (a - 1) // lcm)
