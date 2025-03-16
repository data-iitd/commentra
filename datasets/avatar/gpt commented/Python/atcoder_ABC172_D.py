import sys

# Function to read a line from standard input and remove trailing whitespace
def rs(): 
    return sys.stdin.readline().rstrip()

# Function to read an integer from standard input
def ri(): 
    return int(rs())

# Function to read a line from standard input and return a list of strings
def rs_(): 
    return [_ for _ in rs().split()]

# Function to read a line from standard input and return a list of integers
def ri_(): 
    return [int(_) for _ in rs().split()]

# Read the integer N from input
N = ri()

# Initialize the answer variable to accumulate the result
ans = 0

# Loop through each integer from 1 to N (inclusive)
for i in range(1, N + 1):
    # Calculate the contribution of the current integer i to the answer
    ans += i * (N // i) * (N // i + 1) // 2

# Print the final result
print(ans)
