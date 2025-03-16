# I/O
import sys
import math
import collections

# Helper functions for reading different data types from input
def next_str():
	return sys.stdin.readline().strip()

def next_int():
	return int(next_str())

def next_float():
	return float(next_str())

def next_int_slice(n):
	arr = next_str().split()
	return [int(x) for x in arr]

def next_float_slice(n):
	arr = next_str().split()
	return [float(x) for x in arr]

# Modulus value for modular arithmetic
MOD = 1000000007

# Infinite value for comparison
INF = 1 << 60

# Mon represents a monster with x-coordinate and height
class Mon:
	def __init__(self, x, h):
		self.x = x
		self.h = h

# Mons is a slice of Mon structures
Mons = collections.namedtuple('Mons', ['arr'])

# Custom sorting function for Mons
def sort_mons(a):
	return sorted(a.arr, key=lambda x: x.x)

# Node represents a node in the priority queue with x-coordinate and damage
class Node:
	def __init__(self, x, h):
		self.x = x
		self.h = h

# Queue is a priority queue implemented as a slice with custom push, pop, and isEmpty functions
class Queue:
	def __init__(self):
		self.arr = []

	def push(self, v):
		self.arr.append(v)

	def first(self):
		return self.arr[0]

	def pop(self):
		res = self.arr[0]
		self.arr = self.arr[1:]
		return res

	def isEmpty(self):
		return len(self.arr) == 0

# Main function initializes variables, sorts monsters, and calculates the answer
def main():
	# Read input values N, D, and A from input
	N, D, A = next_int(), next_int(), next_int()

	# Initialize a slice of Mon structures called M
	M = Mons([Mon(next_int(), next_int()) for _ in range(N)])

	# Sort the M slice based on x-coordinates
	M = Mons(sort_mons(M))

	# Initialize an empty priority queue called q
	q = Queue()

	# Initialize answer variable ans to 0 and total variable total to 0
	ans = 0
	total = 0

	# Iterate through each Mon in the sorted M slice
	for i in range(N):
		# Current Mon
		m = M.arr[i]

		# While the priority queue is not empty and the current Mon's x-coordinate is smaller than the x-coordinate of the first Node in the priority queue
		while not q.isEmpty() and q.first().x < m.x:
			# Pop the first Node from the priority queue
			total -= q.pop().h

		# If the total damage is less than the Mon's height, calculate the remaining damage, add it to the answer, and push it to the priority queue
		if total < m.h:
			damage = m.h - total
			ans += damage
			q.push(Node(m.x + 2*D, damage))
			total += damage
	# Print the answer
	print(ans)

# 