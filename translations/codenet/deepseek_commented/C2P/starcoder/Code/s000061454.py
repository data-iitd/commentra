# <START-OF-CODE>

# Variable declarations
a, b, n = 0, 0, 0 # Input values and loop counters
sum = 0 # To store the sum of the digits
i, j = 0, 0 # Loop counters

# Infinite loop
while True:
    # Read three integers from standard input
    a, b, n = map(int, input().split())

    # Reduce 'a' to its remainder when divided by 'b'
    a -= a // b * b

    # Initialize sum to zero
    sum = 0

    # Outer loop runs 'n' times
    for i in range(1, n + 1):
        # Multiply 'a' by 10 to shift the decimal point
        a *= 10

        # Inner loop iterates from 9 down to 0
        for j in range(9, -1, -1):
            # Find the largest digit 'j' such that 'b*j' is less than or equal to 'a'
            if b * j <= a:
                break

        # Subtract 'b*j' from 'a' and add 'j' to the sum
        a -= b * j
        sum += j

    # Output the sum of the digits
    print(sum)

# 