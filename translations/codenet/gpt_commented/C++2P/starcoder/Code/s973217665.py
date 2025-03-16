
# Read the number of test cases
n = int(input())

# Process each test case
while n > 0:
    # Read the values of p and q
    p, q = map(int, input().split())

    # Calculate the length l based on the Euclidean distance from the origin
    l = int(sqrt(p*p + q*q))

    # Initialize a flag to check if the current case is prime
    isprime = 1

    # Check all combinations of i and j within the range [0, l)
    for i in range(l):
        for j in range(l):
            # Calculate the sum of squares of i and j
            x = i*i + j*j

            # Skip values of x that are not in the valid range
            if x <= 1 or x >= p*p + q*q: continue

            # Check the conditions for primality based on the given formula
            if ((i*p + j*q) % x == 0 and (i*q - j*p) % x == 0):
                isprime = 0 # Set isprime to false if conditions are met

    # Output "P" if prime, otherwise output "C"
    print("P" if isprime else "C")

    # Decrement the number of test cases
    n -= 1

# 