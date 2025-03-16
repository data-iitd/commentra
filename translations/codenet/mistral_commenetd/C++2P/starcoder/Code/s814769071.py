
#pragma region
#define _USE_MATH_DEFINES
import math
import sys
import io
import os
import time
import collections
import itertools
import functools
import random
import string

# Input and Output
# I/O speed can be slow sometimes.
# Using buffered input will greatly improve performance.
# To use buffered input, replace "cin" and "cout" with "sys.stdin" and "sys.stdout".
# To disable buffering, replace "ios::sync_with_stdio(false);" with "cin.tie(0);" and "cout.tie(0);".
#
# Example:
#
# replace:
# cin >> n >> k;
# with:
# n, k = map(int, sys.stdin.readline().split())
#
# replace:
# cout << res << endl;
# with:
# print(res)
#
# replace:
# ios::sync_with_stdio(false);
# with:
# sys.stdin = io.StringIO(sys.stdin.read())
#
# replace:
# cin.tie(0);
# cout.tie(0);
# with:
# pass
#
# Note:
#
# If you are using Python 2, replace "ll" with "long long"
# If you are using Python 3, replace "ll" with "int"
#
# Note:
#
# If you are using Python 2, replace "cin" and "cout" with "raw_input()" and "print"
# If you are using Python 3, replace "cin" and "cout" with "input()" and "print"
#
# Note:
#
# If you are using Python 2, replace "ios::sync_with_stdio(false);" with "sys.stdin = io.StringIO(sys.stdin.read())"
# If you are using Python 3, replace "ios::sync_with_stdio(false);" with "pass"
#
# Note:
#
# If you are using Python 2, replace "cin.tie(0);" and "cout.tie(0);" with "pass"
# If you are using Python 3, replace "cin.tie(0);" and "cout.tie(0);" with "import sys"
#
# Note:
#
# If you are using Python 2, replace "ll" with "long long"
# If you are using Python 3, replace "ll" with "int"
#
# Note:
#
# If you are using Python 2, replace "cin" and "cout" with "raw_input()" and "print"
# If you are using Python 3, replace "cin" and "cout" with "input()" and "print"
#
# Note:
#
# If you are using Python 2, replace "ios::sync_with_stdio(false);" with "sys.stdin = io.StringIO(sys.stdin.read())"
# If you are using Python 3, replace "ios::sync_with_stdio(false);" with "pass"
#
# Note:
#
# If you are using Python 2, replace "cin.tie(0);" and "cout.tie(0);" with "pass"
# If you are using Python 3, replace "cin.tie(0);" and "cout.tie(0);" with "import sys"
#pragma endregion

# Main function
def main():
	# Read input
	n, k = map(int, input().split())

	# Calculate the maximum number of unique elements in a subset of size k from 1 to n
	mx = n * (n + 1) / 2 - (n - k)*(n - k + 1) / 2

	# Calculate the minimum number of unique elements in a subset of size k from 1 to n
	mn = k * (k - 1) / 2

	# Initialize result variable
	res = 0

	# Iterate through all possible subset sizes from k to n+1
	for i in range(k, n + 1):
		# Calculate the number of unique elements in the current subset
		res += mx - mn + 1

		# Update the maximum and minimum number of unique elements for the next iteration
		mx += n - i
		mn += i

	# Print the final result
	print(res)

# Entry point
if __name__ == '__main__':
	main()

# 