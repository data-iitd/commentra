# Read the values of N and K from standard input
N, K = map(int, input().split())

# Initialize a list to store the input elements
v = list(map(int, input().split()))

# Calculate the number of groups needed based on the formula ceil((N-1) / (K-1))
# This is done using integer arithmetic to avoid floating-point operations
count = (N - 1 + (K - 2)) // (K - 1)

# Output the calculated count of groups
print(count)

# <END-OF-CODE>
