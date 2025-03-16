
import sys

# Initialize a new scanner to read input from standard input
scanner = sys.stdin

# Read the first line of input containing 4 integers and store them in ns slice
print("Reading input")
ns = [int(x) for x in scanner.readline().split()]

# Sort the ns slice in ascending order
print("Sorting the numbers in ns slice")
ns.sort()

# Check if the sorted ns slice matches the specific condition (1, 4, 7, 9)
print("Checking the condition")
if ns[0] == 1 and ns[1] == 4 and ns[2] == 7 and ns[3] == 9:
	print("The condition is true, print YES")
	print("Output: YES")
else:
	print("The condition is false, print NO")
	print("Output: NO")

# 