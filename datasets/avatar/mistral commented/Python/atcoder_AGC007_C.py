# Importing the sys module for reading input in buffer
import sys

# Function to read input from standard input in buffer
read = sys.stdin.buffer.read

# Function to read a single line from standard input in buffer
readline = sys.stdin.buffer.readline

# Function to read multiple lines from standard input in buffer
readlines = sys.stdin.buffer.readlines

# Reading input as three integers: N, d, and x
N, d, x = map(int, read().split())

# Function definition: main function takes three arguments N, d, and x
def main(N, d, x):
    # Initializing the result variable to 0
    ret = 0

    # Loop continues as long as N is greater than 0
    while N > 0:
        # Adding the current term to the result
        ret += d + (N - 0.5) * x

        # Updating the value of d for the next iteration
        d += d / N + (5 * x) / (2 * N)

        # Updating the value of x for the next iteration
        x += 2 * x / N

        # Decrementing the value of N for the next iteration
        N -= 1

    # Returning the final result
    return ret

# Calling the main function and printing the result
print(main(N, d, x))
