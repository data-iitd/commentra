# Constants
mod = 998244353
facNum = 300001

# Main function
def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    # Read an integer N from the standard input
    N = int(data[0])
    
    # Initialize a variable sum to 0
    total_sum = 0
    
    # Loop through numbers from 1 to N
    for i in range(1, N + 1):
        # If the number is not divisible by 3 or 5, add it to the sum
        if i % 3 != 0 and i % 5 != 0:
            total_sum += i
    
    # Print the result to the standard output
    print(total_sum)

# Math functions
def pow_mod(a, n):
    # Calculate a^n modulo mod
    ans = 1
    while n > 0:
        if n & 1:
            ans = ans * a % mod
        a = a * a % mod
        n >>= 1
    return ans

def gcd(a, b):
    # Calculate the greatest common divisor of a and b
    if a < b:
        return gcd(b, a)
    while b != 0:
        a, b = b, a % b
    return a

def min_val(a, b):
    # Return the minimum of a and b
    return a if a < b else b

# Combination function
def combination(n, k, fac, ifac):
    # Calculate the binomial coefficient (n choose k) modulo mod
    if n < k or n < 0:
        return 0
    if k == 0:
        return 1
    return ifac[k] * ifac[n - k] % mod * fac[n] % mod

# Factorial function
def factorial():
    # Calculate and return the factorial of all numbers from 0 to facNum-1
    fac = [0] * facNum
    ifac = [0] * facNum
    fac[0] = 1
    ifac[0] = 1
    for i in range(1, facNum):
        fac[i] = fac[i - 1] * i % mod
        ifac[i] = ifac[i - 1] * pow_mod(i, mod - 2) % mod
    return fac, ifac

# Lower bound function
def lower_bound(vs, v):
    # Calculate the index of the first element in vs that is greater than or equal to v
    n = len(vs) // 2
    m = len(vs)
    while m != n:
        if vs[n] < v:
            n = (m - n + 1) // 2 + n
        else:
            m = n
            n = n // 2
    return n

# IntSlice function
def int_slice(n, init):
    # Create and initialize a slice of length n with the given initial value
    return [init] * n

# Call the main function
if __name__ == "__main__":
    main()

# <END-OF-CODE>
