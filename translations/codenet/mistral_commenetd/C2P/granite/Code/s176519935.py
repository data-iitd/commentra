

import heapq
# Import the heapq module for using the heap data structure

n, m = map(int, input().split())
# Read the number of elements n and the number of queries m from the standard input

a = list(map(int, input().split()))
# Read the elements of the array 'a' from the standard input

heapq.heapify(a)
# Convert the array 'a' into a heap using the 'heapify' function from the heapq module

for i in range(m):
	tm = heapq.heappop(a)
	# Pop an element from the heap using the 'heappop' function

	tm //= 2
	# Divide the popped element by 2

	heapq.heappush(a, tm)
	# Add the divided element back to the heap using the 'heappush' function

ans = sum(a)
# Calculate the sum of the elements in the heap using the'sum' function

print(ans)
# Print the sum of the elements in the heap to the standard output

