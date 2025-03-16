
# Read the values of N and K from standard input
N, K = map(int, input().split())

# Initialize a list of size N to store the input elements
v = [0] * N

# Read N integers from standard input and store them in the list v
for i in range(N):
    v[i] = int(input())

# Calculate the number of groups needed based on the formula ceil((N-1) / (K-1))
# This is done using integer division and the floor division operator //
count = (N - 1) // (K - 1) + ((N - 1) % (K - 1) > 0)

# Output the calculated count of groups
print(count)

