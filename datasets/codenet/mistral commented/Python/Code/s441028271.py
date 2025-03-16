
# Import the map function from the built-in module
# This function applies a given function to every item in an iterable
# and returns a list of the results
map = builtins.map

# Get input as a list of integers, and unpack it into variables a, b, c, and k
a, b, c, k = list(map(int, input().split()))

# Check if the value of k is even or odd
if k % 2 == 0:
    # If k is even, print the difference between a and b
    print(a - b)
else:
    # If k is odd, print the difference between b and a
    print(b - a)