def G(a, b):
    # Calculate the greatest common divisor (GCD) of a and b using the Euclidean algorithm
    while a % b != 0:
        a, b = b, a % b
    return b

def L(a, b):
    # Calculate the least common multiple (LCM) of a and b using the relationship between GCD and LCM
    return a * b // G(a, b)

# Read four integers x, y, a, and b from the input
l = input().split(' ')
x, y, a, b = int(l[0]), int(l[1]), int(l[2]), int(l[3])

# Calculate the LCM of x and y
lcm = L(x, y)

# Compute the number of integers in the range from a to b that are divisible by lcm
# and print the result
print(b // lcm - (a - 1) // lcm)
