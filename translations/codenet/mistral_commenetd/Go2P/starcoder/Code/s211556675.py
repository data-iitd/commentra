# I/O
import sys

# Arithmetic
def max(*nums):
	m = nums[0]
	for i in nums:
		if m < i:
			m = i
	return m

def min(*nums):
	m = nums[0]
	for i in nums:
		if m > i:
			m = i
	return m

def abs(x):
	if x > 0:
		return x
	return -x

def pow(x, y):
	res = 1
	for i in range(y):
		res *= x
	return res

# Sort
class Val:
	def __init__(self, id, num):
		self.id = id
		self.num = num

# ByNum is a type alias for a slice of Val structs, used for sorting
ByNum = list[Val]

def ByNumLen(a):
	return len(a)

def ByNumLess(a, i, j):
	return a[i].num < a[j].num

def ByNumSwap(a, i, j):
	a[i], a[j] = a[j], a[i]

# Main function
def main():
	# Read input values
	A, B, C, K = map(int, input().split())

	# Find the maximum value among A, B, and C
	ma = max(A, B, C)

	# Calculate the rest of the numbers that need to be multiplied by 2 to reach or exceed K
	rest = 0
	if ma == A:
		rest += B + C
	elif ma == B:
		rest += A + C
	else:
		rest += A + B

	# Calculate the final answer
	answer = pow(ma, K) + rest

	# Write the answer to the output
	print(answer)

# 