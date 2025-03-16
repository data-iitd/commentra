# Import the math module for mathematical functions
# Define a function to read an integer input from the user
def next_int ( ):
    # Read an integer input from the user and convert it to an integer
    return int(input())
# Define a function to read a list of integers from the user
def next_ints ( ):
    # Read a list of integers from the user and convert each element to an integer
    return list(map(int, input().split()))
# Read an integer `n` from the user
n = next_int()
# Initialize a variable `t` to zero
t = 0
# Iterate through the range of integers from 0 to n-1
for i in range(n):
    # Check if the index i is odd
    if i + 1 & 1:
        # If it is odd, increment the variable t by 1
        t += 1
# Print the result t/n as the output
print(t / n)
