import sys
input = sys.stdin.buffer.readline

def main():
	
	# SegmentTree Class to handle range queries and updates
	class SegmentTree:
		
		# Initialize the segment tree with a given size and default value
		def __init__(self, size, default):
			self.size = 2**(size-1).bit_length()  # Calculate the size of the segment tree
			self.default = default  # Set the default value for the segment tree
			self.seg = [default]*(2*self.size-1)  # Initialize the segment tree array

		# Function to define how to combine two segments (max in this case)
		def segfunc(self, x, y):
			return max(x, y)

		# Update the segment tree with a new value at index k
		def update(self, k, x):
			k += self.size - 1  # Adjust index to the leaf position
			self.seg[k] = x  # Update the value at the leaf
			# Update the parent nodes
			while k:
				k = (k - 1) // 2  # Move up to the parent
				self.seg[k] = self.segfunc(self.seg[2 * k + 1], self.seg[2 * k + 2])  # Update the parent value

		# Query the segment tree for the range [p, q)
		def query(self, p, q):
			if q <= p:  # If the range is invalid, return the default value
				return self.default
			p += self.size - 1  # Adjust index to the leaf position
			q += self.size - 2  # Adjust index to the leaf position
			ret = self.default  # Initialize return value
			# Process the range
			while q - p > 1:
				if p & 1 == 0:  # If p is even, include the segment at p
					ret = self.segfunc(ret, self.seg[p])
				if q & 1 == 1:  # If q is odd, include the segment at q
					ret = self.segfunc(ret, self.seg[q])
					q -= 1  # Move left
				p = p // 2  # Move up to the parent
				q = (q - 1) // 2  # Move up to the parent
			# Combine the last two segments
			ret = self.segfunc(self.segfunc(ret, self.seg[p]), self.seg[q])
			return ret  # Return the result of the query

		# Print the current state of the segment tree for debugging
		def seg_print(self):
			print(self.seg)
		
	# Read the number of elements
	N = int(input())
	# Read the array of integers
	a = list(map(int, input().split()))
	# Initialize the answer array with indices + 1
	ans = [i + 1 for i in range(N)]
	# Create a left segment tree for processing
	left_seg = SegmentTree(N, 0)
	# Process the array from left to right
	for i, num in enumerate(a):
	    ans[num - 1] *= i + 1 - left_seg.query(0, num)  # Update the answer based on the left segment tree
	    left_seg.update(num - 1, i + 1)  # Update the left segment tree with the current index

	# Create a right segment tree for processing
	right_seg = SegmentTree(N, 0)
	# Process the array from right to left
	for i, num in enumerate(a[::-1]):
	    ans[num - 1] *= i + 1 - right_seg.query(0, num)  # Update the answer based on the right segment tree
	    right_seg.update(num - 1, i + 1)  # Update the right segment tree with the current index
	
	# Print the final sum of the answers
	print(sum(ans))

if __name__ == "__main__":
	main()
