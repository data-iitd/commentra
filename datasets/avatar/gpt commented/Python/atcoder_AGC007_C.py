import sys

# Set up input reading methods for efficient reading from standard input
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines

# Read the input values for N, d, and x, and convert them to integers
N, d, x = map(int, read().split())

def main(N, d, x):
    # Initialize the result variable to accumulate the final value
    ret = 0
    
    # Loop until N becomes zero
    while N:
        # Update the result by adding the current d and a calculated value based on N and x
        ret += d + (N - 0.5) * x
        
        # Update d based on its current value, N, and x
        d = d + (d / N) + (5 * x) / (2 * N)
        
        # Update x based on its current value and N
        x += 2 * x / N
        
        # Decrement N to move to the next iteration
        N -= 1
    
    # Return the accumulated result
    return ret

# Call the main function with the input values and print the result
print(main(N, d, x))
