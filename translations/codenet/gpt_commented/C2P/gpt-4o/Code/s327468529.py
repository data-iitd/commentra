import sys
from collections import defaultdict

# Constants
BIG = 2000000007
VERYBIG = 20000000000000007
MOD = 1000000007
FOD = 998244353

# Function to compute a^x mod modulo using binary exponentiation
def bitpow(a, x, modulo):
    result = 1
    while x:
        if x & 1:
            result = (result * a) % modulo
        x //= 2
        a = (a * a) % modulo
    return result

# Function to perform modular division a / b mod modulo
def divide(a, b, modulo):
    return (a * bitpow(b, modulo - 2, modulo)) % modulo

# Function to compute n choose r modulo m
def ncr(n, r, m, frac, invf):
    if n < 0 or r < 0 or n < r:
        return 0
    return frac[n] * (invf[r] * invf[n - r] % m) % m

# Main solving function
def solve(n, s):
    cnt = [0, 0, 0]  # Count of R, G, B
    pcnt = 0  # Potential combinations
    result = 1  # Variable to store the result

    # Process the input string and calculate the result based on color counts
    for i in range(n * 3):
        if s[i] == 'R':
            v = 0  # Red
        elif s[i] == 'G':
            v = 1  # Green
        elif s[i] == 'B':
            v = 2  # Blue

        # Check if there are available colors to form combinations
        if cnt[(v + 1) % 3] and cnt[(v + 2) % 3]:
            result *= pcnt  # Multiply by the count of available combinations
            pcnt -= 1  # Decrease the count of available combinations
            result %= FOD  # Apply modulo
            cnt[(v + 1) % 3] -= 1  # Decrease count of the first color
            cnt[(v + 2) % 3] -= 1  # Decrease count of the second color
        else:
            # If there are more of the other two colors than the current color
            if (cnt[(v + 1) % 3] + cnt[(v + 2) % 3]) > cnt[v]:
                result *= (cnt[(v + 1) % 3] + cnt[(v + 2) % 3]) - cnt[v]
                result %= FOD  # Apply modulo
                pcnt += 1  # Increase the count of available combinations
            cnt[v] += 1  # Increase count of the current color

    # Calculate the factorial of n for final result
    for i in range(1, n + 1):
        result = (result * i) % FOD

    # Output the result
    print(result)

# Main function to execute the program
if __name__ == "__main__":
    n = int(sys.stdin.readline().strip())
    m = int(sys.stdin.readline().strip())
    s = sys.stdin.readline().strip()  # Read the string input

    # Call the solve function to compute the result
    solve(n, s)

# <END-OF-CODE>
