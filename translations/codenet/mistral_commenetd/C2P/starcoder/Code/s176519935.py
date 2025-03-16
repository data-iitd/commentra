
# Include the standard input/output library

# Declare a long long array 'heap' of size 100000 and initialize its size to zero
heap = [0] * 100000
sz = 0

# Declare a function 'push' for adding an element to the heap
def push(x):
	global sz
	# Declare a variable 'i' for storing the index of the newly added element in the heap

	i = sz
	# Assign the value of the variable'sz' to the variable 'i'

	while i > 0:
		# Perform the heapify operation from the bottom to the top
		p = (i - 1) // 2
		# Calculate the index of the parent node of the current node 'i'

		if heap[p] >= x: break
		# If the parent node is greater than or equal to the current node, then break the loop

		heap[i] = heap[p]
		# Swap the parent node with the current node

		i = p
		# Move to the parent node

	heap[i] = x
	# Assign the value x to the current node
	sz += 1
	# Increment the size of the heap by 1

# Declare a function 'pop' for popping an element from the heap
def pop():
	global sz
	# Declare a variable'ret' for storing the value of the root node

	ret = heap[0]
	# Assign the value of the root node to the variable'ret'

	x = heap[sz - 1]
	# x is the last element in the heap after popping the root node

	i = 0
	# i is the index of the current node

	while i * 2 + 1 < sz:
		# Perform the heapify operation from the bottom to the top after popping the root node

		a = i * 2 + 1
		# a is the index of the left child node of the current node 'i'

		b = i * 2 + 2
		# b is the index of the right child node of the current node 'i'

		if b < sz and heap[b] > heap[a]: a = b
		# If the right child node has a greater value than the left child node, then assign the index of the right child node to a

		if heap[a] <= x: break
		# If the value of the node to be swapped is less than or equal to the value of the current node, then break the loop

		heap[i] = heap[a]
		# Swap the values of the current node and the node to be swapped

		i = a
		# Move to the node to be swapped

	heap[i] = x
	# Assign the value of the current node to the node that was swapped

	sz -= 1
	# Decrement the size of the heap by 1

	return ret
	# Return the value of the root node before popping it

# Declare a function'main' for the execution of the program
def main():
	n, m = map(int, input().split())
	# Read the number of elements n and the number of queries m from the standard input

	a = list(map(int, input().split()))
	# Read the elements of the array 'a' from the standard input

	for i in range(n): push(a[i])
	# Add each element of the array 'a' to the heap using the 'push' function

	for i in range(m):
		tm = pop()
		# Pop an element from the heap

		tm //= 2
		# Divide the popped element by 2

		push(tm)
		# Add the divided element back to the heap using the 'push' function

	ans = 0
	# Initialize the variable 'ans' to 0 for storing the sum of the elements in the heap

	for i in range(n): ans += heap[i]
	# Calculate the sum of the elements in the heap using a loop

	print(ans)
	# Print the sum of the elements in the heap to the standard output

# Execute the function'main'
if __name__ == "__main__": main()

# 