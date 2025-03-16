
# <START-OF-CODE>

# Declare variables
n, i, j, q, x, y, sum = 0, 0, 0, 0, [], [], 0

# Read the number of elements in array x
n = int(input())

# Read n elements into array x
for i in range(n):
	x.append(int(input()))

# Read the number of queries
q = int(input())

# Read q elements into array y
for i in range(q):
	y.append(int(input()))

# Initialize sum to count how many elements in y are found in x
for i in range(q):
	# Check each element in y against all elements in x
	for j in range(n):
		# If a match is found, increment sum and break the inner loop
		if( y[i] == x[j]):
			sum = sum + 1
			break

# Output the total count of matches found
print(sum)

# 