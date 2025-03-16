from collections import defaultdict

B = 13131  # Define a constant base for hashing
N = 500000 + 7  # Define the maximum length of the string + 7 for safety

n = 0  # Declare an integer to store the length of the string
s = [''] * N  # Declare a list to store the input string
f = [0] * N  # Declare a list to store the hash values
g = [0] * N  # Declare a list to store position-dependent values
map_freq = defaultdict(int)  # Declare a dictionary to store the frequency of hash values
cnt = 0  # Declare a variable to count the number of valid substrings

# Define the pow function to calculate a^k using binary exponentiation
def pow(a, k):
    if k < 0:
        k += (1 << 63) - 1  # Handle negative exponents
    t = 1  # Initialize the result to 1
    while k:  # Square and halve the exponent
        if k & 1:
            t *= a  # If the exponent is odd, multiply the result
        a *= a
        k >>= 1
    return t  # Return the result

# Main function to execute the program
if __name__ == "__main__":
    n, s[1:] = int(input()), list(input().strip())  # Read the input values for n and the string s
    for i in range(1, n + 1):  # Iterate through the string
        if s[i - 1] == '+' or s[i - 1] == '-':  # Check if the character is '+' or '-'
            f[i] = f[i - 1] + (1 if s[i - 1] == '+' else -1) * pow(B, g[i])
            g[i] = g[i - 1]
        else:
            f[i] = f[i - 1]
            g[i] = g[i - 1] + (-1 if s[i - 1] == '<' else 1)  # Update the position-dependent values

    for i in range(n, 0, -1):  # Iterate through the string in reverse
        map_freq[f[i]] += 1
        cnt += map_freq[f[n] * pow(B, g[i - 1]) + f[i - 1]]  # Count the valid substrings

    print(cnt)  # Print the count of valid substrings

# <END-OF-CODE>
