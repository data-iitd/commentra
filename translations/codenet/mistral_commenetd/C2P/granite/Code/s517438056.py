

# Read the number of rows and columns from the user
N, D = map(int, input("Enter the number of rows and columns: ").split())

# Initialize the 2D matrix
matrix = []
for i in range(N):
	row = list(map(int, input(f"Enter the elements of row {i + 1}: ").split()))
	matrix.append(row)

# Calculate the number of identical rows
k = 0
for i in range(N - 1):
	for j in range(i + 1, N):
		m = 0 # Initialize the variable m to 0
		for n in range(D):
			# Calculate the difference between the corresponding elements of two rows and square it
			m += (matrix[i][n] - matrix[j][n]) ** 2
		# Calculate the square root of the sum of squared differences
		l = m ** 0.5
		# If the square root is an integer, increment the counter k
		if l.is_integer(): k += 1

# Print the result
print(k)

