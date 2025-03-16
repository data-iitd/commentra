import sys

def main():
    # Read the integer n, which represents the number of elements
    n = int(input().strip())
    
    # Read the next line of input and split it into an array of strings
    sa = input().strip().split()
    
    # Initialize an integer array to hold the parsed values
    a = [int(x) for x in sa]
    
    # Define a modulus value for calculations to prevent overflow
    mod = 1000000007
    
    # Initialize a variable to hold the factorial product
    p = 1
    
    # Calculate the factorial of n modulo mod
    for i in range(2, n + 1):
        p = p * i % mod
    
    # Initialize an array to hold cumulative sums of modular inverses
    q = [0] * n
    q[0] = 1  # Base case for the first element
    
    # Calculate the cumulative sum of modular inverses
    for i in range(1, n):
        q[i] = (q[i - 1] + modinv(i + 1, mod)) % mod
    
    # Initialize a variable to hold the final answer
    ans = 0
    
    # Calculate the final answer using the cumulative sums and input array
    for i in range(n):
        val = q[i] + q[n - i - 1] - 1
        val *= a[i]
        val %= mod
        val *= p
        val %= mod
        ans += val
        ans %= mod
    
    # Print the final result
    print(ans)

# Function to compute the modular inverse using the Extended Euclidean Algorithm
def modinv(a, m):
    b = m
    u = 1
    v = 0
    while b > 0:
        t = a // b
        a -= t * b
        u, v = v, u - t * v
        b = a % b
        a = b
    u %= m
    if u < 0:
        u += m
    return u

if __name__ == "__main__":
    main()
