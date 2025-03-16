#!/usr/bin/env python3

import sys

# Define a deque structure with two slices to represent the front and back.
class deque:
	def __init__(self):
		self.front = []
		self.back = []

	# Check if the front of the deque is empty.
	def isEmptyFront(self):
		return len(self.front) == 0

	# Check if the back of the deque is empty.
	def isEmptyBack(self):
		return len(self.back) == 0

	# Push a byte to the back of the deque.
	def pushBack(self, v):
		self.back.append(v)

	# Push a byte to the front of the deque.
	def pushFront(self, v):
		self.front.append(v)

	# Pop a byte from the back of the deque, or from the front if the back is empty.
	def popBack(self):
		if not self.isEmptyBack():
			v = self.back.pop()
		elif not self.isEmptyFront():
			v = self.front.pop(0)
		else:
			return False, None
		return True, v

	# Pop a byte from the front of the deque, or from the back if the front is empty.
	def popFront(self):
		if not self.isEmptyFront():
			v = self.front.pop()
		elif not self.isEmptyBack():
			v = self.back.pop(0)
		else:
			return False, None
		return True, v

	# Get a byte at a specific index in the deque.
	def get(self, idx):
		tot = len(self.front) + len(self.back)
		if idx < tot:
			if idx < len(self.front):
				v = self.front[len(self.front)-1-idx] # Access from the front.
			else:
				v = self.back[idx-len(self.front)] # Access from the back.
		else:
			v = None
		return v

# Define an operation structure to hold the operation type and character.
class op:
	def __init__(self):
		self.rev = False
		self.front = False
		self.c = None

# Reverse a string and return the reversed version.
def rev(s):
	r = []
	for i in range(len(s)-1, -1, -1):
		r.append(s[i])
	return ''.join(r)

# Main function to execute the program logic.
def main():
	S = sys.stdin.readline().strip() # Read the initial string S.
	Q = int(sys.stdin.readline().strip()) # Read the number of operations Q.
	ops = [] # Create a slice to hold operations.

	# Read each operation and populate the ops slice.
	for i in range(Q):
		q = int(sys.stdin.readline().strip())
		if q == 1:
			ops.append(op()) # Mark operation as reverse.
		else:
			f, c = sys.stdin.readline().strip().split()
			f = int(f)
			ops.append(op()) # Mark operation as front insertion.
			ops[i].c = c

	# Prepare a sum array to track the number of reversals.
	sum = [0] * (Q+1)
	for i in range(Q-1, 0, -1):
		if ops[i].rev:
			sum[i-1] = sum[i] + 1 # Increment count if operation is reverse.
		else:
			sum[i-1] = sum[i] # Carry forward the count if not reverse.

	# Reverse the string S if the total number of reversals is odd.
	if sum[0]%2 == 1:
		S = rev(S)

	deq = deque() # Initialize a deque to manage character insertions.
	for i in range(Q):
		if not ops[i].rev: # Process only non-reverse operations.
			if ops[i].front:
				if sum[i]%2 == 1:
					deq.pushBack(ops[i].c) # Push to back if the reversal count is odd.
				else:
					deq.pushFront(ops[i].c) # Push to front if the reversal count is even.
			else:
				if sum[i]%2 == 1:
					deq.pushFront(ops[i].c) # Push to front if the reversal count is odd.
				else:
					deq.pushBack(ops[i].c) # Push to back if the reversal count is even.

	# Prepare to write the final result to standard output.
	wtr = sys.stdout.write
	# Output the characters in the correct order.
	for i in range(len(deq.front)-1, -1, -1):
		wtr(deq.front[i]) # Print front characters in reverse order.
	wtr(S) # Print the original string S.
	for i in range(len(deq.back)):
		wtr(deq.back[i]) # Print back characters in order.
	wtr('\n') # Print a newline at the end.

if __name__ == "__main__":
	main()

