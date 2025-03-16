import decimal

def main():
    # Initialize decimal for precision
    decimal.getcontext().prec = 30  # Set precision for decimal operations

    # Read three float values: N, d, and x
    N = float(input())
    d = float(input())
    x = float(input())

    # Initialize Decimal to store the result with precision
    ans = decimal.Decimal("0.0")

    # Continue the loop until N is greater than 0.5
    while N > 0.5:
        # Calculate a value using Decimal for precision
        adnum = decimal.Decimal(d + x * (N - 0.5))
        ans += adnum

        # Update the values of d and x based on the current value of N
        d = (N + 1.0) * d / N + (5.0 * x) / (2.0 * N)
        x = (1.0 + (2.0 / N)) * x

        # Decrement N by 1 in each iteration
        N -= 1

    # Print the result formatted to a specific number of decimal places
    print(f"{ans:.20f}")

if __name__ == "__main__":
    main()

# <END-OF-CODE>
