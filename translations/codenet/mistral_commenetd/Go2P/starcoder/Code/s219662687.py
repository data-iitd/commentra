# Package declaration and importing necessary packages
import sys
import math
import bisect

# Main function declaration and initialization of constants
def main():
	INF = 10**11 # Large constant value for initializing arrays

	# Reading input values from standard input
	A = int(input())
	B = int(input())
	Q = int(input())

	# Initializing arrays s and t with size A+2 and B+2 respectively
	# The first and last elements are initialized with -INF and INF respectively
	s = [INF] * (A+2)
	s[0], s[A+1] = -INF, INF

	# Reading A elements of array s from standard input
	for i in range(1, A+1):
		s[i] = int(input())

	# Initializing array t with size B+2
	# The first and last elements are initialized with -INF and INF respectively
	t = [INF] * (B+2)
	t[0], t[B+1] = -INF, INF

	# Reading B elements of array t from standard input
	for i in range(1, B+1):
		t[i] = int(input())

	# Processing each query
	for i in range(Q):
		# Reading query value x from standard input
		x = int(input())

		# Finding the indices b and d of array s and t respectively
		# where s[b] and t[d] are the smallest elements greater than x
		b = bisect.bisect_left(s, x)
		d = bisect.bisect_left(t, x)

		# Computing the minimum distance between x and any pair of elements S and T
		# from arrays s and t respectively
		res = INF
		for S in [s[b-1], s[b]]:
			for T in [t[d-1], t[d]]:
				# Computing the absolute difference between S and x, and T and S
				d1, d2 = abs(S-x), abs(T-S)

				# Updating the minimum distance if the current pair has a smaller distance
				res = min(res, min(d1, d2))

		# Printing the minimum distance for the current query
		print(res)

# Input reading helper functions
def nextInt():
	return int(input())

def nextFloat():
	return float(input())

def nextString():
	return str(input())

# Helper functions for array manipulation and arithmetic operations
def abs(x):
	return abs(x)

def min(x, y):
	return min(x, y)

def max(x, y):
	return max(x, y)

