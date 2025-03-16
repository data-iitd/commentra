import sys

# Read user inputs from standard input using input()
x, y = map(int, sys.stdin.readline().split())

# Check if the absolute difference between x and y is less than or equal to 1
if abs(x - y) <= 1:
    # If the condition is true, print "Brown" to the standard output
    print("Brown")
else:
    # If the condition is false, print "Alice" to the standard output
    print("Alice")

# End of code
