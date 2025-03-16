import sys

# Use readline for faster input reading
input = sys.stdin.readline

# Read the number of elements
n = int(input())

# Read the list of integers from input
w = list(map(int, input().split()))

# Initialize a variable 'c' to track the output state
c = 2

# Iterate through each element in the list 'w'
for i in w:
    # If the current element is 1, print the current value of 'c'
    if i == 1:
        print(c)
    # If the current element is even, toggle 'c' between 2 and 3
    elif i % 2 == 0:
        c = 3 - c  # This will switch c between 2 and 3
        print(c)
    # If the current element is odd (and not 1), print the current value of 'c'
    else:
        print(c)
