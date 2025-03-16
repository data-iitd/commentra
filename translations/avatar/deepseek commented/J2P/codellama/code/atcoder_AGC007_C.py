
import math
import decimal

# Initialize Scanner to read input from the user
scan = input()

# Read three double values: N, d, and x
N = float(scan)
d = float(scan)
x = float(scan)

# Initialize BigDecimal to store the result with precision
ans = decimal.Decimal(0.0)

# Continue the loop until N is greater than 0.5
while N > 0.5:
    # Calculate a value using BigDecimal for precision
    adnum = decimal.Decimal(d + x * (N - 0.5))
    ans = ans + adnum

    # Update the values of d and x based on the current value of N
    d = (N + 1.0) * d / N + (5.0 * x) / (2.0 * N)
    x = (1.0 + (2.0 / N)) * x

    # Decrement N by 1 in each iteration
    N -= 1

# Initialize DecimalFormat to format the output
format = decimal.Decimal(20)

# Print the result formatted to a specific number of decimal places
print(format.format(ans))

# END-OF-CODE
