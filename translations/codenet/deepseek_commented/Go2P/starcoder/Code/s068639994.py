def main():
	# Get the number of elements in the slice.
	n = int(input())
	# Get the slice of integers.
	ls = list(map(int, input().split()))
	# Create a reversed version of the slice.
	lsRev = ls.copy()
	# Sort the original slice in ascending order.
	ls.sort()
	# Sort the reversed slice in descending order.
	lsRev.sort(reverse=True)

	# Initialize the answer variable.
	ans = 0
	# Loop through the slice to calculate the answer.
	for i in range(n):
		for j in range(i+1, n):
			# Calculate p and q based on the current elements.
			p, q = min(ls[i], ls[j]), max(ls[i], ls[j])
			# Calculate x and y based on p and q.
			x, y = q-p, q+p

			# Find the left boundary using binary search.
			l = bisect.bisect_left(ls, x)
			# Find the right boundary using binary search.
			r = n - bisect.bisect_right(lsRev, y)

			# Calculate the sum of valid pairs.
			sum = r - l
			# Adjust the sum if the current indices are within the range.
			if (i >= l) and (i <= r):
				sum -= 1
			if (j >= l) and (j <= r):
				sum -= 1
			# Ensure the sum is not negative.
			sum = max(0, sum)
			# Add the sum to the answer.
			ans += sum
	# Divide the answer by 3 to get the final result.
	ans //= 3
	# Print the final answer.
	print(ans)

# Helper functions to find the minimum and maximum of two integers.
def min(a, b):
	if a < b:
		return a
	return b

def max(a, b):
	if a > b:
		return a
	return b

# 