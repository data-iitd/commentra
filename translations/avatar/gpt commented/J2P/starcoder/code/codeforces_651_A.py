import sys

# Read two integers from input
a, b = map(int, sys.stdin.readline().split())

# Initialize counter for the number of operations
c = 0

# Check for the special case where both a and b are 1
if a == 1 and b == 1:
    print(0) # Output 0 operations needed
else:
    # Loop until both a and b are non-positive
    while a >= 1 or b >= 1:
        # If a is greater than or equal to b, perform operation on a
        if a >= b:
            b += 1 # Increment b
            a -= 2 # Decrement a by 2
        else:
            # If b is greater than a, perform operation on b
            a += 1 # Increment a
            b -= 2 # Decrement b by 2

        # Check if either a or b has become non-positive
        if a <= 0 or b <= 0:
            c += 1 # Increment operation counter and break
            break
        c += 1 # Increment operation counter

# Output the total number of operations performed
print(c)

# 