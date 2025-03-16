
# Initialize variables N and X with user input
N, X = map(int, input().split())

# Create a vector L of size N to store the elements
L = [0] * N

# Read elements of vector L from user input
for i in range(N):
	L[i] = int(input())

# Initialize variable i and d to zero
i = 0
d = 0

# Loop through the vector L until the sum d exceeds X
while i < N and d <= X:
	# Add the current element of vector L to the sum d
	d += L[i]
	i += 1

# Print the index of the last element in the vector L that was added to the sum d
print(i+1)

