from decimal import Decimal, getcontext  # Importing Decimal for high precision arithmetic
import sys  # Importing sys for reading input

# Set the precision for Decimal operations
getcontext().prec = 30

def main():
    # Reading input values from the user
    N = float(input())
    d = float(input())
    x = float(input())

    ans = Decimal("0.0")  # Initializing an answer variable of Decimal type with zero value

    # Calculating the answer using the given formula
    while N > 0.5:
        adnum = Decimal(d + x * (N - 0.5))  # Calculating the next term of the sum
        ans += adnum  # Adding the next term to the answer

        # Updating the values of d and x for the next iteration
        d = (N + 1.0) * d / N + (5.0 * x) / (2.0 * N)
        x = (1.0 + (2.0 / N)) * x

        N -= 1  # Decreasing the value of N by 1 for the next iteration

    # Printing the final answer with 20 decimal places
    print(f"{ans:.20f}")

if __name__ == "__main__":
    main()

# <END-OF-CODE>
