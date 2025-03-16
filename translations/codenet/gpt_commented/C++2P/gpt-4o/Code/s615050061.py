from collections import defaultdict

# Define constants for base and maximum size
B = 13131
N = 500000 + 7

# Declare global variables
n = 0  # Length of the input string
s = [''] * N  # Input string
f = [0] * N  # Array to store computed values based on the input string
g = [0] * N  # Array to store the shift values
map_count = defaultdict(int)  # Map to count occurrences of computed values
cnt = 0  # Counter for the final result

# Function to compute power of a number with a given exponent
def pow(a, k):
    # Adjust exponent if negative
    if k < 0:
        k += (1 << 63) - 1
    t = 1  # Initialize result
    # Exponentiation by squaring
    while k:
        if k & 1:
            t *= a  # Multiply result if current bit is set
        a *= a
        k >>= 1
    return t  # Return computed power

def main():
    global n, cnt
    # Read input values: number of operations and the operations string
    n, s[1:] = int(input()), input().strip()
    
    # Process each character in the input string
    for i in range(1, n + 1):
        # If the character is '+' or '-', update f and g arrays
        if s[i - 1] == '+' or s[i - 1] == '-':
            f[i] = f[i - 1] + (1 if s[i - 1] == '+' else -1) * pow(B, g[i] := g[i - 1])
        else:
            # If the character is '<' or '>', update f and g arrays accordingly
            f[i] = f[i - 1]  # No change in f
            g[i] = g[i - 1] + (-1 if s[i - 1] == '<' else 1)  # Update g based on direction

    # Iterate backwards through the string to count valid combinations
    for i in range(n, 0, -1):
        map_count[f[i]] += 1  # Increment the count of the current f value
        # Update the counter with the number of valid combinations found
        cnt += map_count[f[n] * pow(B, g[i - 1]) + f[i - 1]]

    # Output the final count of valid combinations
    print(cnt)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
