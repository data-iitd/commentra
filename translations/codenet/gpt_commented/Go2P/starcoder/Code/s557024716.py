/*
URL:
https://atcoder.jp/contests/m-solutions2020/tasks/m_solutions2020_b
*/

import sys
import math

# Constants
MOD = 1000000000 + 7
ALPHABET_NUM = 26
INF_INT64 = math.pow(2, 63) - 1
INF_BIT60 = 1 << 60
INF_INT32 = math.pow(2, 31) - 1
INF_BIT30 = 1 << 30
NIL = -1

# Variables
a, b, c = 0, 0, 0
k = 0
patterns = []

# Main function
def main():
	global a, b, c, k, patterns

	# Read three integers and the number of patterns
	a, b, c = ReadInt3()
	k = ReadInt()

	# Generate all possible patterns of length k from the set {0, 1, 2, 3}
	patterns = DuplicatePatterns([0, 1, 2, 3], k)

	# Iterate through each generated pattern
	for P in patterns:
		r, g, b = a, b, c # Initialize color values for each pattern
		# Apply the pattern to modify the color values
		for i in range(len(P)):
			if P[i] == 0:
				continue # Skip if the pattern element is 0
			elif P[i] == 1:
				r *= 2 # Double the red value
			elif P[i] == 2:
				g *= 2 # Double the green value
			elif P[i] == 3:
				b *= 2 # Double the blue value

		# Check if the modified values satisfy the condition
		if g > r and b > g:
			print("Yes") # Print "Yes" if the condition is met
			return
		else:
			print("No") # Print "No" if no pattern satisfies the condition

# Function to generate all patterns of length k from the given elements
def DuplicatePatterns(elems, k):
	return dupliRec([], elems, k) # Start the recursive pattern generation

# Recursive function to generate patterns
def dupliRec(pattern, elems, k):
	if len(pattern) == k:
		return [pattern] # Return the completed pattern

	res = [] # Slice to hold the results
	# Iterate through each element to build patterns
	for e in elems:
		newPattern = pattern[:] # Copy the existing pattern
		newPattern.append(e) # Append the new element

		# Recursively generate patterns with the new element added
		res += dupliRec(newPattern, elems, k)
	return res # Return all generated patterns

# Read an integer
def ReadInt():
	return int(sys.stdin.readline())

# Read three integers
def ReadInt3():
	return map(int, sys.stdin.readline().split())

# Read a float
def ReadFloat():
	return float(sys.stdin.readline())

# Read a string
def ReadString():
	return sys.stdin.readline().strip()

# Read a string list
def ReadStringList():
	return sys.stdin.readline().strip().split()

# Read a string list
def ReadStringList():
	return sys.stdin.readline().strip().split()

# Read a integer list
def ReadIntList():
	return map(int, sys.stdin.readline().strip().split())

# Read a integer list
def ReadIntList():
	return map(int, sys.stdin.readline().strip().split())

# Read a integer list
def ReadIntList():
	return map(int, sys.stdin.readline().strip().split())

# Read a integer list
def ReadIntList():
	return map(int, sys.stdin.readline().strip().split())

# Read a integer list
def ReadIntList():
	return map(int, sys.stdin.readline().strip().split())

# Read a integer list
def ReadIntList():
	return map(int, sys.stdin.readline().strip().split())

# Read a integer list
def ReadIntList():
	return map(int, sys.stdin.readline().strip().split())

# Read a integer list
def ReadIntList():
	return map(int, sys.stdin.readline().strip().split())

# Read a integer list
def ReadIntList():
	return map(int, sys.stdin.readline().strip().split())

# Read a integer list
def ReadIntList():
	return map(int, sys.stdin.readline().strip().split())

# Read a integer list
def ReadIntList():
	return map(int, sys.stdin.readline().strip().split())

# Read a integer list
def ReadIntList():
	return map(int, sys.stdin.readline().strip().split())

# Read a integer list
def ReadIntList():
	return map(int, sys.stdin.readline().strip().split())

# Read a integer list
def ReadIntList():
	return map(int, sys.stdin.readline().strip().split())

# Read a integer list
def ReadIntList():
	return map(int, sys.stdin.readline().strip().split())

# Read a integer list
def ReadIntList():
	return map(int, sys.stdin.readline().strip().split())

# Read a integer list
def ReadIntList():
	return map(int, sys.stdin.readline().strip().split())

# Read a integer list
def ReadIntList():
	return map(int, sys.stdin.readline().strip().split())

# Read a integer list
def ReadIntList():
	return map(int, sys.stdin.readline().strip().split())

# Read a integer list
def ReadIntList():
	return map(int, sys.stdin.readline().strip().split())

# Read a integer list
def ReadIntList():
	return map(int, sys.stdin.readline().strip().split())

# Read a integer list
def ReadIntList():
	return map(int, sys.stdin.readline().strip().split())

# Read a integer list
def ReadIntList():
	return map(int, sys.stdin.readline().strip().split())

# Read a integer list
def ReadIntList():
	return map(int, sys.stdin.readline().strip().split())

# Read a integer list
def ReadIntList():
	return map(int, sys.stdin.readline().strip().split())

# Read a integer list
def ReadIntList():
	return map(int, sys.stdin.readline().strip().split())

# Read a integer list
def ReadIntList():
	return map(int, sys.stdin.readline().strip().split())

# Read a integer list
def ReadIntList():
	return map(int, sys.stdin.readline().strip().split())

# Read a integer list
def ReadIntList():
	return map(int, sys.stdin.readline().strip().split())

# Read a integer list
def ReadIntList():
	return map(int, sys.stdin.readline().strip().split())

# Read a integer list
def ReadIntList():
	return map(int, sys.stdin.readline().strip().split())

# Read a integer list
def ReadIntList():
	return map(int, sys.stdin.readline().strip().split())

# Read a integer list
def ReadIntList():
	return map(int, sys.stdin.readline().strip().split())

# Read a integer list
def ReadIntList():
	return map(int, sys.stdin.readline().strip().split())

# Read a integer list
def ReadIntList():
	return map(int, sys.stdin.readline().strip().split())

# Read a integer list
def ReadIntList():
	return map(int, sys.stdin.readline().strip().split())

# Read a integer list
def ReadIntList():
	return map(int, sys.stdin.readline().strip().split())

# Read a integer list
def ReadIntList():
	return map(int, sys.stdin.readline().strip().split())

# Read a integer list
def ReadIntList():
	return map(int, sys.stdin.readline().strip().split())

# Read a integer list
def ReadIntList():
	return map(int, sys.stdin.readline().strip().split())

# Read a integer list
def ReadIntList():
	return map(int, sys.stdin.readline().strip().split())

# Read a integer list
def ReadIntList():
	return map(int, sys.stdin.readline().strip().split())

# Read a integer list
def ReadIntList():
	return map(int, sys.stdin.readline().strip().split())

# Read a integer list
def ReadIntList():
	return map(int, sys.stdin.readline().strip().split())

# Read a integer list
def ReadIntList():
	return map(int, sys.stdin.readline().strip().split())

# Read a integer list
def ReadIntList():
	return map(int, sys.stdin.readline().strip().split())

# Read a integer list
def ReadIntList():
	return map(int, sys.stdin.readline().strip().split())

# Read a integer list
def ReadIntList():
	return map(int, sys.stdin.readline().strip().split())

# Read a integer list
def ReadIntList():
	return map(int, sys.stdin.readline().strip().split())

# Read a integer list
def ReadIntList():
	return map(int, sys.stdin.readline().strip().split())

# Read a integer list
def ReadIntList():
	return map(int, sys.stdin.readline().strip().split())

# Read a integer list
def ReadIntList():
	return map(int, sys.stdin.readline().strip().split())

# Read a integer list
def ReadIntList():
	return map(int, sys.stdin.readline().strip().split())

# Read a integer list
def ReadIntList():
	return map(int, sys.stdin.readline().strip().split())

# Read a integer list
def ReadIntList():
	return map(int, sys.stdin.readline().strip().split())

# Read a integer list
def ReadIntList():
	return map(int, sys.stdin.readline().strip().split())

# Read a integer list
def ReadIntList():
	return map(int, sys.stdin.readline().strip().split())

# Read a integer list
def ReadIntList():
	return map(int, sys.stdin.readline().strip().split())

# Read a integer list
def ReadIntList():
	return map(int, sys.stdin.readline().strip().split())

# Read a integer list
def ReadIntList():
	return map(int, sys.stdin.readline().strip().split())

# Read a integer list
def ReadIntList():
	return map(int, sys.stdin.readline().strip().split())

# Read a integer list
def ReadIntList():
	return map(int, sys.stdin.readline().strip().split())

# Read a integer list
def ReadIntList():
	return map(int, sys.stdin.readline().strip().split())

# Read a integer list
def ReadIntList():
	return map(int, sys.stdin.readline().strip().split())

# Read a integer list
def ReadIntList():
	return map(int, sys.stdin.readline().strip().split())

# Read a integer list
def ReadIntList():
	return map(int, sys.stdin.readline().strip().split())

# Read a integer list
def ReadIntList():
	return map(int, sys.stdin.readline().strip().split())

# Read a integer list
def ReadIntList():
	return map(int, sys.stdin.readline().strip().split())

# Read a integer list
def ReadIntList():
	return map(int, sys.stdin.readline().strip().split())

# Read a integer list
def ReadIntList():
	return map(int, sys.stdin.readline().strip().split())

# Read a integer list
def ReadIntList():
	return map(int, sys.stdin.readline().strip().split())

# Read a integer list
def ReadIntList():
	return map(int, sys.stdin.readline().strip().split())

# Read a integer list
def ReadIntList():
	return map(int, sys.stdin.readline().strip().split())

# Read a integer list
def ReadIntList():
	return map(int, sys.stdin.readline().strip().split())

# Read a integer list
def ReadIntList():
	return map(int, sys.stdin.readline().strip().split())

# Read a integer list
def ReadIntList():
	return map(int, sys.stdin.readline().strip().split())

# Read a integer list
def ReadIntList():
	return map(int, sys.stdin.readline().strip().split())

# Read a integer list
def ReadIntList():
	return map(int, sys.stdin.readline().strip().split())

# Read a integer list
def ReadIntList():
	return m