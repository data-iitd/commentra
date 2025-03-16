
# <START-OF-CODE>
# <NAME>
# 20150112
#
# Declare variables
N = 0
D = 0
i = 0
j = 0
k = 0
n = 0
l = 0.0
matrix = []

# Read the number of rows and columns from the user
N = int(raw_input("Enter the number of rows and columns: "))

# Allocate memory for the 2D matrix
matrix = [[0 for x in range(D)] for y in range(N)]

# Read the elements of the matrix from the user
for i in range(N):
	print "Row %d: " % (i + 1),
	for j in range(D):
		matrix[i][j] = int(raw_input())

# Calculate the number of identical rows
k = 0
for i in range(N - 1):
	for j in range(i + 1, N):
		m = 0 # Initialize the variable m to 0
		for n in range(D):
			# Calculate the difference between the corresponding elements of two rows and square it
			m += (matrix[i][n] - matrix[j][n]) * (matrix[i][n] - matrix[j][n])
		# Calculate the square root of the sum of squared differences
		l = math.sqrt(m)
		# If the square root is an integer, increment the counter k
		if (math.ceil(l) == math.floor(l)): k += 1

# Print the result
print k
# 