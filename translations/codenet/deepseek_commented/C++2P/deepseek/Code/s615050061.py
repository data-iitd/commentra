from sys import stdin, stdout
from collections import defaultdict

# Define a type alias for unsigned long long
u64 = int

# Define constants
B = 13131
N = 500000 + 7

# Declare variables
n = 0
s = [""] * N
f = [0] * N
g = [0] * N
map = defaultdict(int)
cnt = 0

# Define the pow function to calculate a^k using binary exponentiation
def pow(a, k):
    if k < 0:
        k += (1 << 63) - 1  # Handle negative exponents
    t = 1
    while k:
        if k & 1:
            t *= a
        a *= a
        k >>= 1
    return t

# Main function to execute the program
def main():
    global n, s, f, g, map, cnt
    
    # Read input values for n and the string s
    n = int(stdin.readline().strip())
    s = stdin.readline().strip()
    
    # Iterate through the string
    for i in range(1, n + 1):
        if s[i - 1] == '+' or s[i - 1] == '-':
            f[i] = f[i - 1] + (1 if s[i - 1] == '+' else -1) * pow(B, g[i - 1])
        else:
            f[i] = f[i - 1]
            g[i] = g[i - 1] + (-1 if s[i - 1] == '<' else 1)
    
    # Iterate through the string in reverse
    for i in range(n, 0, -1):
        map[f[i]] += 1
        cnt += map[f[n] * pow(B, g[i - 1]) + f[i - 1]]
    
    # Print the count of valid substrings
    stdout.write(str(cnt) + '\n')

# Call the main function
if __name__ == "__main__":
    main()
