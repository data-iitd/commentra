# Define a lambda function to read an integer input
num_inp = lambda: int(input())

# Define a lambda function to read a list of integers from input
arr_inp = lambda: list(map(int, input().split()))

# Define a lambda function to read a space-separated list of integers as a map object
sp_inp = lambda: map(int, input().split())

# Read the input from the first line of the standard input, sort it, and convert it to a list of integers
a = sorted(map(int, [*open(0)][1].split()))

# Check if any element in the list 'a' is not divisible by the first element of 'a'
# If all elements are divisible, print the first element; otherwise, print -1
print([a[0], -1][any(x % a[0] for x in a)])
