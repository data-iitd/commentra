
# <START-OF-CODE>

# Python 3 program to find the minimum total distance to a median value

# Function to find the minimum total distance to a median value
def solve():
	# Read the number of elements
	n = int(input())
	# Read the integer slice of size n
	as = list(map(int, input().split()))

	# Create a new slice to store adjusted values
	xs = [0] * n
	for i, a in enumerate(as):
		# Adjust each element by subtracting its index and adding 1
		xs[i] = a - i + 1
	# Sort the adjusted values
	xs.sort()

	# Find the median value from the sorted slice
	b = xs[n//2]
	ans = 0
	# Calculate the total distance from each element to the median
	for x in xs:
		ans += abs(x - b)
	# Output the result
	print(ans)

# Function to return the absolute value of an integer
def abs(n):
	if n < 0:
		return -n
	return n

# Driver Code
if __name__ == '__main__':
	solve()

# 