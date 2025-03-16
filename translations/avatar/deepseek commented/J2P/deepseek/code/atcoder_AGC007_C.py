import decimal
from decimal import Decimal

def main():
    # Initialize Scanner to read input from the user
    scan = input()

    # Read three double values: N, d, and x
    N = float(scan)
    d = float(scan)
    x = float(scan)

    # Initialize Decimal to store the result with precision
    ans = Decimal("0.0")

    # Continue the loop until N is greater than 0.5
    while N > 0.5:
        # Calculate a value using Decimal for precision
        adnum = Decimal(d + x * (N - 0.5))
        ans += adnum

        # Update the values of d and x based on the current value of N
        d = ((N + 1.0) * d / N) + ((5.0 * x) / (2.0 * N))
        x = (1.0 + (2.0 / N)) * x

        # Decrement N by 1 in each iteration
        N -= 1

    # Initialize DecimalFormat to format the output
    format = decimal.getcontext().create_decimal_from_float(0.1)
    format = format.quantize(decimal.Decimal('0.00000000000000000000'))

    # Print the result formatted to a specific number of decimal places
    print(format)

if __name__ == "__main__":
    main()
