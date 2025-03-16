# Package main is the entry point of the program
import sys

# Define a deque (double ended queue) type
class deque:
	def __init__(self):
		# Initialize the front and back slices to store the elements
		self.front = []
		self.back = []

	# Function to check if deque is empty at the front
	def isEmptyFront(self):
		# Return true if the length of front slice is zero
		return len(self.front) == 0

	# Function to check if deque is empty at the back
	def isEmptyBack(self):
		# Return true if the length of back slice is zero
		return len(self.back) == 0

	# Function to add an element at the back of the deque
	def pushBack(self, v):
		# Append the given byte to the back slice
		self.back.append(v)

	# Function to add an element at the front of the deque
	def pushFront(self, v):
		# Append the given byte to the front slice
		self.front.append(v)

	# Function to remove an element from the back of the deque and return it
	def popBack(self):
		# If the deque is not empty at the back, pop the last element and return true
		r = True
		if not self.isEmptyBack():
			v = self.back[len(self.back)-1]
			self.back = self.back[:len(self.back)-1]
		elif not self.isEmptyFront(): # If the deque is empty at the back but not at the front
			v = self.front[0]          # Pop the first element
			self.front = self.front[1:]   # Update the front slice
		else:                       # If the deque is empty at both front and back
			r = False                  # Return false
		return r, v

	# Function to remove an element from the front of the deque and return it
	def popFront(self):
		# If the deque is not empty at the front, pop the first element and return true
		r = True
		if not self.isEmptyFront():
			v = self.front[len(self.front)-1]
			self.front = self.front[:len(self.front)-1]
		elif not self.isEmptyBack(): # If the deque is empty at the front but not at the back
			v = self.back[0]          # Pop the last element
			self.back = self.back[1:]   # Update the back slice
		else:                       # If the deque is empty at both front and back
			r = False                  # Return false
		return r, v

	# Function to get an element from the deque by its index
	def get(self, idx):
		# Calculate the total length of the deque
		tot = len(self.front) + len(self.back)
		# If the index is valid, return the corresponding element
		var v byte
		if idx < tot:
			if idx < len(self.front):
				v = self.front[len(self.front)-1-idx]
			else:
				v = self.back[idx-len(self.front)]
		return v

# Function to reverse a given string
def rev(s):
	# Create a byte slice with the length of the given string
	r = [0] * len(s)
	# Initialize the indices i and j
	i, j = len(s)-1, 0
	# Iterate through the string from the end to the beginning
	for i >= 0:
		# Store the character at index i in the reverse string
		r[j] = s[i]
		# Increment j
		j++
		# Decrement i
		i--
	# Return the reversed string
	return ''.join(r)

# Main function to read input and process it
def main():
	# Read the input string S from the standard input
	S = sys.stdin.readline().rstrip()
	# Read the number of operations Q from the standard input
	Q = int(sys.stdin.readline().rstrip())
	# Initialize an array of operations ops with the given size
	ops = [0] * Q
	# Read the operations one by one and store them in the ops array
	for i in range(Q):
		# Read the type of operation (reverse or not)
		q = int(sys.stdin.readline().rstrip())
		# If the operation is to reverse the string, set the rev field to true
		if q == 1:
			ops[i].rev = True
		else:
			# Else, read the front flag and the character c from the standard input
			f, c = sys.stdin.readline().rstrip().split()
			# Set the front field based on the front flag
			if f == '1':
				ops[i].front = True
			# Set the character c
			ops[i].c = c
	# Initialize an array of sums sum with the given size
	sum = [0] * (Q+1)
	# Initialize the sum of the first operation
	sum[0] = 0
	# Iterate through the remaining operations and calculate their sums
	for i in range(Q-1, -1, -1):
		# If the current operation is to reverse the string, increment the previous sum
		if ops[i].rev:
			sum[i-1] = sum[i] + 1
		else:
			# Else, set the previous sum to the current sum
			sum[i-1] = sum[i]
	# If the sum of the first operation is odd, reverse the input string
	if sum[0]%2 == 1:
		S = rev(S)
	# Initialize an empty deque deq
	deq = deque()
	# Iterate through the operations and process them based on their type
	for i in range(Q):
		# If the current operation is not to reverse the string
		if not ops[i].rev:
			# If the operation is to add a character at the front, process it accordingly
			if ops[i].front:
				# If the previous sum is odd, push the character to the front of the deque
				if sum[i]%2 == 1:
					deq.pushFront(ops[i].c)
				else:
					deq.pushBack(ops[i].c)
			else: # Else, process the operation to add a character at the end
				# If the previous sum is odd, push the character to the end of the deque
				if sum[i]%2 == 1:
					deq.pushBack(ops[i].c)
				else:
					deq.pushFront(ops[i].c)
		# Write the result to the standard output
		# Write the characters in the deque to the standard output
		for i in range(len(deq.front)-1, -1, -1):
			sys.stdout.write(deq.front[i])
		# Write the input string to the standard output
		sys.stdout.write(S)
		# Write the characters in the deque to the standard output
		for i in range(len(deq.back)):
			sys.stdout.write(deq.back[i])
		# Flush the buffer and exit
		sys.stdout.flush()

# Entry point of the program
if __name__ == "__main__":
	main()

