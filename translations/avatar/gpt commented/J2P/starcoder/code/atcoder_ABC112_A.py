import sys

# Read the first input as an integer
n = int(sys.stdin.readline())

# Check if the input is 1
if n == 1:
    # If the input is 1, print "Hello World"
    print("Hello World")
else:
    # If the input is not 1, read two more strings
    strs = sys.stdin.readline().split()
    # Parse the two strings as integers and print their sum
    print(int(strs[0]) + int(strs[1]))

# 