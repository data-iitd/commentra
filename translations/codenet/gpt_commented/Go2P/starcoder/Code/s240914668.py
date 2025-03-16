import sys

def main():
	# Read the number of integers
	n = int(sys.stdin.readline())
	# Read the integers into a slice
	a = [int(x) for x in sys.stdin.readline().split()]

	# Initialize the answer counter
	ans = 0

	# Iterate through the slice of integers
	for i in range(n):
		# Set the left and right pointers for the current segment
		l, r = i, i+1

		# Expand the right pointer while the conditions are met
		while r+1 < n and (a[r]-a[l])*(a[r+1]-a[r]) >= 0:
			r += 1

		# Increment the answer for each segment found
		ans += 1
		# Move the left pointer to the end of the current segment
		i = r

	# Output the final count of segments
	print(ans)

if __name__ == "__main__":
	main()

