import sys
import math
import argparse

# Define a large prime number for modulo operations
magic = 1000000007

# Command-line arguments for CPU and memory profiling
parser = argparse.ArgumentParser()
parser.add_argument('--cpuprofile', type=str, help='write cpu profile to file')
parser.add_argument('--memprofile', type=str, help='write mem profile to file')
args = parser.parse_args()

N = 0
p = []

# Function to check if a number exists in the array p
def find(n):
    for i in range(N):
        if n == p[i]:
            return 0  # Number found
    return 1  # Number not found

# Main solving function
def solve():
    global N, p
    io = Io()  # Create a new IO instance for input/output

    # PARSE HELPER SESSION
    # Read and log the input values
    X = io.next_int()  # Read an integer
    log(f"{X}\n")  # Log the integer
    N = io.next_int()  # Read the size of the array
    log(f"{N}\n")  # Log the size
    p = [io.next_int() for _ in range(N)]  # Read integers into the array p
    log(f"p {p[:10]}\n")  # Log the first 10 elements of p

    # Check for numbers around X that are not in the array p
    for i in range(101):
        if find(X - i) == 1:  # Check X - i
            print(X - i)  # Print the result
            sys.exit(0)  # Exit the program
        if find(X + i) == 1:  # Check X + i
            print(X + i)  # Print the result
            sys.exit(0)  # Exit the program

# Main function to execute the program
if __name__ == "__main__":
    if args.cpuprofile:
        import cProfile
        cProfile.run('solve()', args.cpuprofile)

    solve()  # Call the solve function

    if args.memprofile:
        import tracemalloc
        tracemalloc.start()
        snapshot = tracemalloc.take_snapshot()
        snapshot.dump(args.memprofile)

# Libraries

# Io helps parsing inputs from standard input for programming contests.
class Io:
    def __init__(self):
        self.reader = sys.stdin
        self.writer = sys.stdout

    def next_line(self):
        return self.reader.readline().strip()  # Read a line

    def next(self):
        return self.next_line().split()  # Split line into tokens

    def next_int(self):
        return int(self.next()[0])  # Convert the next token to int

    def next_float(self):
        return float(self.next()[0])  # Convert the next token to float

    def print_ln(self, *args):
        print(*args, file=self.writer)  # Write to buffer with linefeed

# Log print single value to standard output
def log(value):
    print(value, file=sys.stderr)  # Log the value to stderr

# Helper functions for mathematical operations

# Returns the minimum of two integers
def int_min(a, b):
    return a if a < b else b

# Returns the maximum of two integers
def int_max(a, b):
    return a if a > b else b

# Direct calculation of combination
def combination(n, m):
    if m > n:
        return 0  # Not possible to choose more than available
    elif m == n or m == 0:
        return 1  # Only one way to choose all or none
    else:
        res = 1
        for i in range(m):
            res *= (n - i)  # Calculate numerator
        for i in range(1, m + 1):
            res //= i  # Calculate denominator
        return res  # Return the combination result

# Calculate combination modulo based on Lucas theorem
def lucas(n, m, p):
    ntemp = n
    mtemp = m
    res = 1
    for _ in range(100):
        nreminder = ntemp % p  # Remainder of n
        ntemp //= p  # Update n
        mreminder = mtemp % p  # Remainder of m
        mtemp //= p  # Update m
        res *= (combination(nreminder, mreminder) % p)  # Combine results
        if ntemp == 0:
            break  # Break if n is exhausted
    return res % p  # Return the result modulo p

# Wrapper function for combination modulo
def comb_mod(n, m, p):
    return lucas(n, m, p)  # Call lucas function

# Function to find divisors of a number
def find_divisors(n):
    if n == 1:
        return []  # 1 has no divisors

    divisors = []
    sqrt = int(math.sqrt(n))  # Calculate the square root of n
    for i in range(2, sqrt + 1):
        if n % i == 0:
            divisors.append(i)  # Append divisor i
            if i != n // i:
                divisors.append(n // i)  # Append corresponding divisor n/i
    divisors.append(n)  # Append n itself as a divisor
    return divisors

# Function to remove duplicates from a list
def remove_duplicate(a):
    return list(set(a))  # Return the list of unique values

# Function to calculate the absolute value
def abs_value(a):
    return a if a > 0 else -a  # Return absolute value

# Function to calculate the greatest common divisor (GCD)
def gcd(a, b):
    while a != 0:
        a, b = b % a, a  # Euclidean algorithm
    return b  # Return the GCD

# Function to calculate power of 2 modulo a given number
def power2mod(n, mod):
    res, x = 1, 2
    while n > 0:
        if n & 1 == 1:
            res = res * x % mod  # Update result if the current bit is set
        x = x * x % mod  # Square the base
        n >>= 1
    return res  # Return the result

# Function to calculate power of 2 with modulo magic
def power2(n):
    return power2mod(n, magic)  # Call power2mod with magic

# <END-OF-CODE>
