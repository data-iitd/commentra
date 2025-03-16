
import math
import decimal

# Reading input values from the user
N = float(input())
d = float(input())
x = float(input())

ans = decimal.Decimal("0.0") # Initializing an answer variable of Decimal type with zero value

# Calculating the answer using the given formula
while N > 0.5:
    adnum = decimal.Decimal(d + x * (N - 0.5)) # Calculating the next term of the sum
    ans += adnum # Adding the next term to the answer

    # Updating the values of d and x for the next iteration
    d = (N + 1.0) * d / N + (5.0 * x) / (2.0 * N)
    x = (1.0 + (2.0 / N)) * x

    N -= 1 # Decreasing the value of N by 1 for the next iteration

# Formatting the output with 20 decimal places
format = decimal.Decimal(10) ** -20

# Printing the final answer with 20 decimal places
print(format.quantize(ans))

