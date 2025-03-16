
import math
import sys

# Function to calculate the modular inverse of a number
def modInv(a, m):
    return pow(a, m - 2, m)

# Function to calculate the power of a number using modular arithmetic
def modPow(b, e, m):
    ans = 1
    x = b % m
    while e > 0:
        if e % 2 == 1:
            ans = (ans * x) % m
        x = (x * x) % m
        e //= 2
    return ans

# Main function to calculate the answer
def main():
    N = int(input())
    A = list(map(int, input().split()))
    mod = 1000000007
    lcm = 1
    for ai in A:
        lcm = (lcm * ai) // math.gcd(lcm, ai)
    lcm %= mod
    ans = 0
    for ai in A:
        ans = (ans + lcm * modInv(ai, mod)) % mod
    print(ans)

# Call the main function
if __name__ == "__main__":
    sys.exit(main())

