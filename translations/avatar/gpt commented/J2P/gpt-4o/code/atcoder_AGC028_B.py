import sys

def modinv(a, m):
    b = m
    u = 1
    v = 0
    while b > 0:
        t = a // b
        a -= t * b
        a, b = b, a
        u -= t * v
        u, v = v, u
    u %= m
    if u < 0:
        u += m
    return u

def main():
    # Read the integer n, which represents the number of elements
    n = int(sys.stdin.readline().strip())
    
    # Read the next line of input and split it into a list of integers
    a = list(map(int, sys.stdin.readline().strip().split()))
    
    # Define a modulus value for calculations to prevent overflow
    mod = 1000000007
    
    # Initialize a variable to hold the factorial product
    p = 1
    
    # Calculate the factorial of n modulo mod
    for i in range(2, n + 1):
        p = p * i % mod
    
    # Initialize a list to hold cumulative sums of modular inverses
    q = [0] * n
    q[0] = 1  # Base case for the first element
    
    # Calculate the cumulative sum of modular inverses
    for i in range(1, n):
        q[i] = (q[i - 1] + modinv(i + 1, mod)) % mod
    
    # Initialize a variable to hold the final answer
    ans = 0
    
    # Calculate the final answer using the cumulative sums and input array
    for i in range(n):
        val = q[i] + q[n - i - 1] - 1  # Combine values from the q array
        val *= a[i]  # Multiply by the corresponding element in a
        val %= mod  # Take modulo
        val *= p  # Multiply by the factorial product
        val %= mod  # Take modulo again
        ans += val  # Add to the final answer
        ans %= mod  # Take modulo to keep the answer manageable
    
    # Print the final result
    print(ans)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
