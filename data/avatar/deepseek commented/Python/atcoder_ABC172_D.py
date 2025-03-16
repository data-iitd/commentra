
import sys

# Function to read a single line from standard input and strip any trailing whitespace characters.
def rs():
    return sys.stdin.readline().rstrip()

# Function to read an integer from standard input.
def ri():
    return int(rs())

# Function to read a list of strings from standard input.
def rs_():
    return [c for c in rs().split()]

# Function to read a list of integers from standard input.
def ri_():
    return [int(c) for c in rs().split()]

# Read the integer value of N from standard input.
N = ri()

# Initialize the variable ans to 0.
ans = 0

# Start a loop that iterates from 1 to N + 1.
for i in range(1, N + 1):
    # Calculate the sum of multiples of i up to N using the formula for the sum of an arithmetic series.
    ans += i * (N // i) * (N // i + 1) // 2

# Print the final value of ans, which represents the sum of multiples of numbers from 1 to N.
print(ans)

