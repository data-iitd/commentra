import sys

# Fast input function to read a character from standard input
def gc():
    return sys.stdin.read(1)

# Function to read a non-negative integer from input
def inp():
    n = 0
    c = gc()
    while c < '0':
        c = gc()
    while c >= '0':
        n = n * 10 + (ord(c) - ord('0'))
        c = gc()
    return n

# Arrays to store frequency counts for two different calculations
f1 = [0] * 100
f2 = [0] * 100

# Function to calculate frequency counts based on the input number
def calc(n):
    k = n % 10  # Extract the last digit of n
    # Reduce n to its first digit by continuously dividing by 10
    while n >= 10:
        n //= 10
    # Update frequency counts for combinations of first and last digits
    f1[10 * k + n] += 1
    f2[n * 10 + k] += 1

# Main function
def main():
    N = inp()  # Read the total number of inputs
    # Process each number from N down to 1
    while N:
        calc(N)
        N -= 1

    ans = 0  # Initialize answer to 0
    # Calculate the final answer by summing the products of corresponding frequencies
    for i in range(100):
        ans += f1[i] * f2[i]
    # Output the final answer
    print(ans)

# Call the main function
main()
