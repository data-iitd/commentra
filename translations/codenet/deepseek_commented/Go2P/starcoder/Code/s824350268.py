
# <START-OF-CODE>

import sys
import math

# Constants
initial_buf_size = 10000
max_buf_size = 1000000
mod = 1e9 + 7

# Input
sc = sys.stdin.readline

# Functions
def main():
	N = get_int()
	sqrt_N = int(math.sqrt(N))

	min = N
	for i in range(1, sqrt_N + 1):
		if N % i!= 0:
			continue

		num = i + (N // i) - 2
		if num < min:
			min = num

	print(min)

def get_int():
	return int(sc())

def get_string():
	return sc().strip()

def abs(a):
	return abs(a)

def pow(p, q):
	return pow(p, q, mod)

def pow_mod(n, p):
	if p == 0:
		return 1
	elif p % 2 == 0:
		t = pow_mod(n, p // 2)
		return calc_mod(t * t)
	else:
		return calc_mod(n * pow_mod(n, p - 1))

def min(nums):
	if len(nums) == 0:
		raise Exception("function min() requires at least one argument.")
	res = nums[0]
	for i in range(len(nums)):
		res = min(res, nums[i])
	return res

def max(nums):
	if len(nums) == 0:
		raise Exception("function max() requires at least one argument.")
	res = nums[0]
	for i in range(len(nums)):
		res = max(res, nums[i])
	return res

def str_search(a, b):
	for i in range(len(a)):
		if a[i] == b:
			return True
	return False

def print_int_array(array):
	print(array)

def calc_mod(x):
	return x % mod

def reverse(s):
	return s[::-1]

def is_prime(n):
	if n < 2:
		return False
	elif n == 2:
		return True
	elif n % 2 == 0:
		return False

	sqrt_N = int(math.sqrt(n))
	for i in range(3, sqrt_N + 1, 2):
		if n % i == 0:
			return False
	return True

# Main
if __name__ == "__main__":
	main()

# 