
# Importing necessary packages

import sys

# Defining global variables

a = []
ans = 0

# Function to perform Depth First Search (DFS) algorithm

def dfs(left, i, res):
	if left == 0:
		global ans
		ans += res
		return

	for j in range(i, len(a)):
		dfs(left-1, j+1, res*a[j])

# Main function definition
def main():
	# Reading the number of test cases
	n = int(sys.stdin.readline())

	# Initializing an empty map to store the frequency of each character
	dic = {}

	# Reading strings and updating the map
	for _ in range(n):
		c = sys.stdin.readline()[0]
		if c in dic:
			dic[c] += 1
		else:
			dic[c] = 1

	# Converting map values to integers and appending them to the 'a' slice
	for _, v in dic.items():
		a.append(v)

	# Calling the 'dfs' function with initial arguments
	dfs(3, 0, 1)

	# Printing the answer
	print(ans)

# Calling the main function
if __name__ == "__main__":
	main()

# 