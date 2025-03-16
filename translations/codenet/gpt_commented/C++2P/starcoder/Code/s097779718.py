# Function to compute the Greatest Common Divisor (GCD) using Euclid's algorithm
def Euclid(x, y):
    # Ensure x is the larger number
    if x < y:
        tmp = x # Store the smaller number in tmp
        x = y   # Assign the larger number to x
        y = tmp # Assign the smaller number to y

    # If y divides x evenly, y is the GCD
    if not(x % y): return y

    # Recursively call Euclid with y and the remainder of x divided by y
    return Euclid(y, x % y)

# Read input values for A and B
A = int(input())
B = int(input())

# Calculate and output the Least Common Multiple (LCM) using the formula LCM(A, B) = (A * B) / GCD(A, B)
print((A * B) / Euclid(A, B))

# 