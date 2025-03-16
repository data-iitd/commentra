# Package main is the entry point of the program
import (
	# bufio package is used for reading from I/O buffers
	import sys
	import math
	import collections
	import bisect
	import heapq
	import time
	import random
	import itertools
	import functools
	import operator
	import re
	import copy
	import os
	import string
	import math
	import collections
	import bisect
	import heapq
	import time
	import random
	import itertools
	import functools
	import operator
	import re
	import copy
	import os
	import string
	# fmt package is used for printing output
	import sys
	import math
	import collections
	import bisect
	import heapq
	import time
	import random
	import itertools
	import functools
	import operator
	import re
	import copy
	import os
	import string
	# os package is used for opening the standard input and output streams
	import sys
	import math
	import collections
	import bisect
	import heapq
	import time
	import random
	import itertools
	import functools
	import operator
	import re
	import copy
	import os
	import string
	# sort package is used for sorting arrays
	import sys
	import math
	import collections
	import bisect
	import heapq
	import time
	import random
	import itertools
	import functools
	import operator
	import re
	import copy
	import os
	import string
	# strconv package is used for converting strings to integers
	import sys
	import math
	import collections
	import bisect
	import heapq
	import time
	import random
	import itertools
	import functools
	import operator
	import re
	import copy
	import os
	import string
)

# Function out is used for printing output to the console
def out(x):
	print(x)

# Variable sc is used for reading input from the standard input stream
sc = sys.stdin

# Function getInt is used for reading an integer value from the standard input
def getInt():
	return int(sc.readline())

# Function getString is used for reading a string value from the standard input
def getString():
	return str(sc.readline())

# Function max returns the maximum value between two integers
def max(a, b):
	# If the first integer is greater than the second integer, return the first integer
	if a > b:
		return a
	# Otherwise, return the second integer
	return b

# Function min returns the minimum value between two integers
def min(a, b):
	# If the first integer is less than the second integer, return the first integer
	if a < b:
		return a
	# Otherwise, return the second integer
	return b

# Function asub returns the absolute difference between two integers
def asub(a, b):
	# If the first integer is greater than the second integer, return the difference
	if a > b:
		return a - b
	# Otherwise, return the negative difference
	return b - a

# Function abs returns the absolute value of an integer
def abs(a):
	# If the integer is greater than or equal to zero, return the integer itself
	if a >= 0:
		return a
	# Otherwise, return the negative of the integer
	return -a

# Function lowerBound returns the index of the first element in the slice that is greater than or equal to the given value
def lowerBound(a, x):
	# Use the bisect.bisect_left function to find the index
	idx = bisect.bisect_left(a, x)
	# Return the index
	return idx

# Function upperBound returns the index of the first element in the slice that is greater than the given value
def upperBound(a, x):
	# Use the bisect.bisect_right function to find the index
	idx = bisect.bisect_right(a, x)
	# Return the index
	return idx

# Type shop represents a data structure for storing two integers
class shop:
	def __init__(self, a, b):
		self.a = a
		self.b = b

# Type Datas is a slice of shop data structures
class Datas(list):
	# Function Len returns the length of the Datas slice
	def Len(self):
		return len(self)

	# Function Swap swaps the positions of two elements in the Datas slice
	def Swap(self, i, j):
		self[i], self[j] = self[j], self[i]

	# Function Less compares two shop data structures and returns true if the first one should come before the second one in a sorted slice
	def Less(self, i, j):
		# Compare the 'a' fields of the two shop structures
		return self[i].a < self[j].a

# Main function is the entry point of the program
def main():
	# Read the number of shops N and the number of customers M from the standard input
	N, M = getInt(), getInt()
	# Initialize a slice of shop data structures named s with a length of N
	s = Datas()
	# For each shop in the slice
	for i in range(N):
		# Read the capacity 'a' and demand 'b' of the shop from the standard input
		a, b = getInt(), getInt()
		# Create a new shop data structure with the read values and assign it to the i-th position in the slice
		s[i] = shop(a, b)
	# Sort the slice in ascending order based on the 'a' field of each shop
	s.sort()

	# Initialize a variable named total to store the total capacity used by the shops
	total = 0
	# For each shop in the sorted slice
	for _, e in s:
		# Calculate the minimum capacity that can be served by the shop without exceeding the maximum demand
		n = min(e.b, M)
		# Add the capacity of the shop multiplied by the number of customers it can serve to the total capacity
		total += n * e.a
		# Decrease the maximum demand by the number of customers served by the shop
		M -= n
		# If the maximum demand becomes zero, break the loop
		if M == 0:
			break
	# Print the total capacity used by the shops
	out(total)

# 