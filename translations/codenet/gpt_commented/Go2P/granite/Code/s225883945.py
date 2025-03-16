
import sys

# Function to read the next line of input as a string
def next():
    return sys.stdin.readline().strip()

# Function to read the next line of input as an integer
def nextInt():
    return int(next())

# Function to read the next line of input as a float64
def nextFloat64():
    return float(next())

# Function to read 'n' integers from input and return them as a list
def nextInts(n):
    return [nextInt() for _ in range(n)]

def main():
    # Read two integers from input: n (number of elements) and k (some parameter)
    n, k = nextInt(), nextInt()
    
    # Read 'n' integers into list 'a'
    a = nextInts(n)
    
    # Avoid unused variable error by assigning a value to the first element of 'a'
    a[0] = 0

    # Initialize sum with the value of k and set ans to 1
    sum = k
    ans = 1
    
    # Loop to calculate how many times we can add k to the sum until it reaches or exceeds n
    while sum < n:
        sum = sum - 1 + k # Update sum by subtracting 1 and adding k
        ans += 1 # Increment the answer counter
    
    # Print the final answer
    print(ans)

