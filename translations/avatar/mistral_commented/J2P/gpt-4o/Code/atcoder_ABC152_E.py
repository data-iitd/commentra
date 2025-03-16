import sys
from math import gcd
from functools import reduce

def lcm(a, b):
    return a * b // gcd(a, b)

def mod_inv(x, mod):
    return mod_pow(x, mod - 2, mod)

def mod_pow(b, e, mod):
    ans = 1
    x = b % mod
    while e != 0:
        if e & 1:
            ans = (ans * x) % mod
        x = (x * x) % mod
        e >>= 1
    return ans

def mod_div(a, b, mod):
    return (a % mod) * mod_inv(b, mod) % mod

def main():
    input = sys.stdin.read
    data = input().split()
    
    N = int(data[0])  # Reading the number of integers N
    A = list(map(int, data[1:N+1]))  # Creating a list A of size N

    mod = 1000000007  # Setting the modulus value
    lcm_value = reduce(lcm, A, 1)  # Calculating the least common multiple (lcm) of all integers in A
    mod_lcm = lcm_value % mod  # Calculating the remainder of lcm modulo mod

    ans = 0  # Initializing answer variable as 0

    # Using a for loop to calculate the answer using modular arithmetic
    for ai in A:
        ans = (ans + mod_div(mod_lcm, ai, mod)) % mod

    # Printing the answer to the standard output stream
    print(ans)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
