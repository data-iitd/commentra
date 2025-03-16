import sys
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines

# Reading the values of N, d, and x from standard input
N, d, x = map(int, read().split())

# Defining the main function to calculate a result based on N, d, and x
def main(N, d, x):
    ret = 0  # Initializing the result variable to accumulate the result
    while N:  # Running the loop while N is greater than 0
        # Incrementing ret by the sum of d and (N - 0.5) * x
        ret += d + (N - 0.5) * x
        
        # Updating the value of d using a complex formula
        d = d + (d / N) + (5 * x) / (2 * N)
        
        # Updating the value of x using another formula
        x += 2 * x / N
        
        # Decrementing N by 1
        N -= 1
    
    # Returning the accumulated result
    return ret

# Printing the result of the main function
print(main(N, d, x))
