import sys
import math

def main():
    # Read the number of elements N
    N = int(input())
    
    # Read N integers into the array A
    A = list(map(int, input().split()))
    
    # Initialize the lcm variable to calculate the least common multiple (LCM)
    lcm = 1
    
    # Calculate the LCM of all elements in the array A
    for ai in A:
        lcm = lcm * ai // math.gcd(lcm, ai)
    
    # Define the modulus value
    mod = 1000000007
    
    # Initialize the answer variable to accumulate results
    ans = 0
    
    # Calculate the sum of modDiv for each element in A
    for ai in A:
        ans = (ans + modDiv(lcm, ai, mod)) % mod
    
    # Print the final result
    print(ans)

# Method to perform modular division
def modDiv(a, b, mod):
    return (a % mod) * modInv(b, mod) % mod

# Method to compute modular inverse using Fermat's Little Theorem
def modInv(x, mod):
    return modPow(x, mod - 2, mod)

# Method to perform modular exponentiation
def modPow(b, e, mod):
    ans = 1
    x = b % mod
    
    # Loop to calculate b^e % mod using exponentiation by squaring
    while e > 0:
        if e % 2 == 1:
            ans = (ans * x) % mod
        x = (x * x) % mod
        e //= 2
    
    # Return the final result of b^e % mod
    return ans

if __name__ == "__main__":
    main()
