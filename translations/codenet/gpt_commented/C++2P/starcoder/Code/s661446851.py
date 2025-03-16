#------------------------------------
#........Bismillahir Rahmanir Rahim....
#..........created by <NAME>.......
#------------------------------------

# Include necessary header files
import sys

# Define constants and type aliases for convenience
mod = 998244353
int = long long
ld = long double
pb = lambda x: x.append
vi = lambda: list(map(int, input().split()))
co = lambda x: print(x, end='\n')
dbg = lambda x: print(x)
bitcount = lambda x: bin(x).count('1')
sz = lambda x: len(x)
all = lambda a: a.begin(), a.end()
ff = lambda x: x[0]
ss = lambda x: x[1]
pii = lambda x, y: (x, y)
lcm = lambda a, b: (a*b)//__import__('math').gcd(a, b)

# Function to solve the problem
def solve():
    n, ans = 1, 0 # Declare variables for input and answer
    n = int(input()) # Read input value for n
    co(not n) # Output the negation of n (0 if n is non-zero, 1 if n is zero)

# Main function
if __name__ == '__main__':
    n = 1 # Initialize n to 1 (can be modified to read input)
    while (n--): solve() # Call the solve function n times

# 