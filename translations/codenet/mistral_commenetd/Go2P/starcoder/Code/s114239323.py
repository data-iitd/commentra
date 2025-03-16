# Package main is the entry point of the program
import sys

# Helper functions to calculate the maximum, minimum, sum, and absolute difference of integers
def Max(a):
	r = a[0]
	for i in range(len(a)):
		if r < a[i]:
			r = a[i]
	return r

def Min(a):
	r = a[0]
	for i in range(len(a)):
		if r > a[i]:
			r = a[i]
	return r

def Sum(a):
	r = 0
	for i in range(len(a)):
		r += a[i]
	return r

def Abs(a):
	if a < 0:
		return -a
	return a

# main function is the entry point of the program
def main():
	# Read the number of test cases N from standard input
	N = int(sys.stdin.readline())

	# Read an array h of N integers from standard input
	h = [int(x) for x in sys.stdin.readline().split()]

	# Initialize a dp array of size N with zeros
	dp = [0] * N
	for i in range(N):
		dp[i] = 0

	# Set the first element of dp to the absolute difference between the first and second elements of h
	dp[1] = Abs(h[0] - h[1])

	# Iterate over the array h from the second element to the last
	for i in range(2, N):
		# Set the current element of dp to the minimum of the previous and previous-previous elements plus the absolute difference between the current and previous/previous elements
		dp[i] = Min([dp[i - 1] + Abs(h[i] - h[i - 1]), dp[i - 2] + Abs(h[i] - h[i - 2])])

	# Print the last element of dp, which is the minimum number of jumps required to reach the last index of h
	print(dp[N-1])

# Helper function to read a single string from standard input
def nextString():
	return sys.stdin.readline().strip()

# Helper function to read a single integer from standard input
def nextInt():
	return int(nextString())

# Helper function to read an array of N integers from standard input
def nextInts(n):
	r = []
	for i in range(n):
		r.append(int(nextString()))
	return r

# 