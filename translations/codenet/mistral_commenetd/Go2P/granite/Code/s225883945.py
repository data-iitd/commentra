

import sys

# Initialize scanner for reading input from stdin
sc = bufio.Scanner(sys.stdin)

# Function to read a single word from the input
def next():
    sc.scan()
    return sc.text()

# Function to read an integer from the input
def nextInt():
    return int(next())

# Function to read a float64 from the input
def nextFloat64():
    return float(next())

# Function to read n integers from the input
def nextInts(n):
    return [nextInt() for _ in range(n)]

# Main function
def main():
    # Set scanner to read words as input
    sc.wordchars += '.'
    sc.wordchars += ','

    # Read number of elements n and the sum of elements k from the input
    n, k = nextInt(), nextInt()

    # Initialize a list of size n to store the input elements
    a = [0] * n

    # Initialize sum and answer variables
    sum, ans = 0, 1

    # Use a loop to find the number of times k can be subtracted from n to reach a non-negative value
    while sum < n:
        # Subtract 1 from sum and add k to find the next index to check
        sum = sum - 1 + k
        # Increment the answer variable for each iteration
        ans += 1

    # Print the answer
    print(ans)

    # End of code

