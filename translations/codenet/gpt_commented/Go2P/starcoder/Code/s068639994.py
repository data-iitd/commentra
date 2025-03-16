
# <START-OF-CODE>

# Read the number of elements
n = int(input())
# Read the integer slice from input
ls = list(map(int, input().split()))
# Create a reversed copy of the original slice
lsRev = ls[:]
lsRev.reverse()
# Sort the original slice in ascending order
ls.sort()
# Sort the reversed slice in descending order
lsRev.sort(reverse=True)

# Initialize the answer variable
ans = 0
# Iterate through all pairs of elements in the sorted slice
for i in range(n):
	for j in range(i+1, n):
		# Determine the minimum and maximum of the two selected elements
		p, q = min(ls[i], ls[j]), max(ls[i], ls[j])
		# Calculate the differences and sums needed for searching
		x, y = q-p, q+p

		# Find the left boundary for elements greater than x
		l = ls.index(x, i)
		# Find the right boundary for elements less than y
		r = n - lsRev.index(y, 0, n-i)

		# Calculate the number of valid elements in the range
		sum = r - l
		# Adjust the count if the current indices are within the range
		if (i >= l) and (i <= r):
			sum -= 1
		if (j >= l) and (j <= r):
			sum -= 1
		# Ensure the sum is non-negative
		sum = max(0, sum)
		# Accumulate the result
		ans += sum

# Divide the final answer by 3 as per the problem requirements
ans //= 3
# Output the result
print(ans)

# 