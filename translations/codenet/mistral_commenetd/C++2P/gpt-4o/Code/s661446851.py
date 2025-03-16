# ------------------------------------
# ........Bismillahir Rahmanir Rahim....
# ..........created by Abdul Aziz.......
# ------------------------------------

mod = 998244353  # Define a constant for modulo arithmetic
int = int  # Define int as int for large input
ld = float  # Define ld for long double precision
pb = list.append  # Define pb for pushing back elements in a list
vi = list  # Define vi as a list of integers
co = print  # Define co for printing output
dbg = lambda x: print(f"{x} = {eval(x)}")  # Define dbg for debugging purpose
bitcount = lambda x: bin(x).count('1')  # Define bitcount for counting set bits
sz = lambda x: len(x)  # Define sz for getting size of a container
all = lambda a: a  # Define all for getting the entire container
ff = 0  # Define ff for getting first element of a pair
ss = 1  # Define ss for getting second element of a pair
pii = tuple  # Define pii as a tuple of integers
lcm = lambda a, b: (a * b) // gcd(a, b)  # Define lcm for finding least common multiple of two numbers

from math import gcd  # Import gcd function from math module

def solve():  # Function declaration for solving the problem
    n = int(input())  # Read input for n
    co(0 if n == 0 else 1)  # Print output if n is not positive

if __name__ == "__main__":  # Main function declaration
    n = 1  # Initialize a variable for number of test cases
    while n > 0:  # Loop for each test case
        solve()  # Call the solve function
        n -= 1  # Decrement the test case counter

# <END-OF-CODE>
