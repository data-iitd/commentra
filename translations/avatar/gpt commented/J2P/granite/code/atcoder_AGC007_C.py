
import decimal

# Set the precision of decimal calculations to 20 digits
decimal.getcontext().prec = 20

# Read three double values from the user: N, d, and x
N = float(input())
d = float(input())
x = float(input())

# Initialize a decimal variable to store the accumulated answer
ans = decimal.Decimal(0.0)

# Loop until N is greater than 0.5
while N > 0.5:
    # Calculate the current term to be added to the answer
    adnum = decimal.Decimal(d + x * (N - 0.5))
    # Add the current term to the accumulated answer
    ans += adnum

    # Update d using the formula provided
    d = (N + 1.0) * d / N + (5.0 * x) / (2.0 * N)
    # Update x using the formula provided
    x = (1.0 + (2.0 / N)) * x

    # Decrement N for the next iteration
    N -= 1

# Print the result
print(ans)

