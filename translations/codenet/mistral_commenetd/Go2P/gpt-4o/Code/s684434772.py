# Import necessary modules
import sys

# The main function is the entry point of the program.
def main():
    # Read 'n' and 'k' from the standard input.
    n = read_int()
    k = read_int()

    # Initialize a variable 'total' to store the sum of combinations.
    total = 0

    # Calculate the sum of combinations of 'n' taken 'i' at a time, where 'i' ranges from 'k' to 'n+1'.
    for i in range(k, n + 2):
        # Calculate the number of combinations using the combi function.
        comb = combi(n, i)
        # Add the number of combinations to the 'total' variable.
        total += comb
        # Apply modulo operation to reduce the size of the number.
        total = total % (pow(10, 9) + 7)

    # Print the result to the standard output.
    print(total)

# The combi function calculates the number of combinations of 'n' taken 'k' at a time using a simplified formula.
def combi(n, k):
    # Calculate the minimum and maximum number of combinations.
    min_comb = (k - 1) * k // 2
    max_comb = (2 * n - k + 1) * k // 2
    # Return the difference between the maximum and minimum number of combinations.
    return max_comb - min_comb + 1

# Util functions for performing basic mathematical operations.

# Abs returns the absolute value of a given integer.
def abs_val(x):
    return x if x >= 0 else -x

# Min returns the minimum value among the given integers.
def min_val(*values):
    return min(values)

# Max returns the maximum value among the given integers.
def max_val(*values):
    return max(values)

# Pow returns the result of raising the base to the given exponent.
def pow_val(base, exponent):
    return base ** exponent

# Read an integer from the standard input.
def read_int():
    return int(sys.stdin.readline().strip())

# Entry point of the program
if __name__ == "__main__":
    main()

# <END-OF-CODE>
