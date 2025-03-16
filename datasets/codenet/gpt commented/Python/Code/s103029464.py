# Read the integer input N, which represents the number of elements
N = int(input())

# Read the list of integers A from input
A = list(map(int, input().split()))

# Initialize a list B of size N with all elements set to 0
B = [0] * N

# Iterate through the indices of B in reverse order
for i in range(N - 1, -1, -1):
    # Initialize a temporary sum to calculate the parity
    tmp_sum = 0
    
    # Calculate the sum of elements in B at specific intervals
    for j in range((i + 1) * 2 - 1, N, i + 1):
        tmp_sum += B[j]  # Add the current element of B to tmp_sum
        tmp_sum %= 2     # Keep tmp_sum as either 0 or 1 (parity)

    # Update B[i] based on the XOR of tmp_sum and A[i]
    B[i] = tmp_sum ^ A[i]

# Print the total number of 1s in B (sum of elements in B)
print(sum(B))

# Print the indices (1-based) of elements in B that are equal to 1
print(*[i + 1 for i, b in enumerate(B) if b == 1])
