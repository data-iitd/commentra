
import decimal
import sys

def main():
    # Initialize decimal.Context to store the result with precision
    ans = decimal.Context(prec=20)

    # Initialize variables
    N = decimal.Decimal(input())
    d = decimal.Decimal(input())
    x = decimal.Decimal(input())

    # Continue the loop until N is greater than 0.5
    while N > 0.5:
        # Calculate a value using decimal.Decimal for precision
        adnum = decimal.Decimal(d + x * (N - 0.5))
        ans += adnum

        # Update the values of d and x based on the current value of N
        d = (N + 1.0) * d / N + (5.0 * x) / (2.0 * N)
        x = (1.0 + (2.0 / N)) * x

        # Decrement N by 1 in each iteration
        N -= 1

    # Print the result formatted to a specific number of decimal places
    print(ans.to_eng_string())

if __name__ == "__main__":
    main()

