
# Python 3 program to find the number of ways to
# reach the n’th stair using 1, 2 or 3 steps.

# Returns the number of ways to reach the n’th
# stair using 1, 2 or 3 steps
def countWays(n):

	# table[i] will be storing the number of ways
	# to reach stair i
	table = [0 for k in range(n + 1)]

	# Base case: There is only one way to reach
	# first stair
	table[0] = 1

	# If only one step is allowed, then we can
	# reach the stair in 1 step
	table[1] = 1

	# If two steps are allowed, then we can reach
	# the stair in two ways:
	# (1) By taking one step and then one step
	table[2] = 2

	# (2) By taking two steps
	table[3] = 3

	# Fill entries for remaining steps
	for i in range(4, n + 1):
		table[i] = table[i - 1] + table[i - 2] + table[i - 3]

	return table[n]

# Driver Code
n = 4
print("Total ways = ", countWays(n))

