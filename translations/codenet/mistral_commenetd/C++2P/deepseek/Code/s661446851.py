# Bismillahir Rahmanir Rahim
# created by Abdul Aziz

# Define a constant for modulo arithmetic
mod = 998244353

# Define int as long long for large input
int = int

# Define ld for long double precision
ld = float

# Define pb for pushing back elements in a list
pb = append

# Define vi as a list of integers
vi = list

# Define co for printing output
def co(x):
    print(x)

# Define dbg for debugging purpose
def dbg(x):
    print(f"{x} = {x}")

# Define bitcount for counting set bits
def bitcount(x):
    return bin(x).count('1')

# Define sz for getting size of a container
def sz(x):
    return len(x)

# Define all for getting iterator to the beginning and end of a container
def all(a):
    return a

# Define ff for getting first element of a pair
def ff(p):
    return p[0]

# Define ss for getting second element of a pair
def ss(p):
    return p[1]

# Define pii as a pair of integers
pii = tuple

# Define lcm for finding least common multiple of two numbers
def lcm(a, b):
    return (a * b) // gcd(a, b)

# Function declaration for solving the problem
def solve():
    n = int(input())  # Read input for n
    co(0 if n else 1)  # Print output if n is not positive

# Main function declaration
if __name__ == "__main__":
    n = 1  # Initialize a variable for number of test cases
    while n:
        solve()  # Call the solve function for each test case
