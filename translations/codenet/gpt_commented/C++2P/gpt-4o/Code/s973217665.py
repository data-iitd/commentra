import math

# Read the number of test cases
n = int(input())

# Process each test case
for _ in range(n):
    p, q = map(int, input().split())

    # Calculate the length l based on the Euclidean distance from the origin
    l = int(math.sqrt(p * p + q * q))

    # Initialize a flag to check if the current case is prime
    isprime = True

    # Check all combinations of i and j within the range [0, l)
    for i in range(l):
        for j in range(l):
            # Calculate the sum of squares of i and j
            x = i * i + j * j

            # Skip values of x that are not in the valid range
            if x <= 1 or x >= p * p + q * q:
                continue

            # Check the conditions for primality based on the given formula
            if (i * p + j * q) % x == 0 and (i * q - j * p) % x == 0:
                isprime = False  # Set isprime to false if conditions are met

    # Output "P" if prime, otherwise output "C"
    print("P" if isprime else "C")

# End of the program
# <END-OF-CODE>
