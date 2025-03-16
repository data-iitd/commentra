
N = int(input())  # Read the length of the list A
A = list(map(int, input().split()))  # Read the list of integers A
B = [0] * N  # Initialize an empty list B with zeros of length N

# The following nested loop structure computes the values of B based on the values of A
for i in range(N - 1, -1, -1):  # Iterate from N-1 down to 0
    tmp_sum = 0  # Initialize tmp_sum to 0
    for j in range((i + 1) * 2 - 1, N, i + 1):  # Iterate over indices that are multiples of (i + 1)
        tmp_sum += B[j]  # Add the value of B[j] to tmp_sum
        tmp_sum %= 2  # Update tmp_sum modulo 2
    B[i] = tmp_sum ^ A[i]  # Set B[i] to the XOR of A[i] and tmp_sum

print(sum(B))  # Print the sum of the list B
print(*[i + 1 for i, b in enumerate(B) if b == 1])  # Print the indices of elements in B that are equal to 1

