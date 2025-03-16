
# Read the values of N and X from standard input
N, X = map(int, input().split())

# Initialize a list L of size N to store the elements
L = [int(input()) for _ in range(N)]

# Initialize index variable and a variable to accumulate the sum
i = 0
d = 0

# Iterate through the elements of the list L
while i < N and d <= X:
    # Accumulate the sum of elements
    d += L[i]
    i += 1

# Output the number of elements processed before exceeding X
print(i)

