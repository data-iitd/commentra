
# Read the number of elements and the threshold from input
N, T = map(int, input().split())

# Initialize an array A to hold the input values
A = list(map(int, input().split()))

# Initialize a vector B to hold the transformed values
B = [0] * N

# Initialize m with the first element of A
m = A[0]

# Calculate the first element of B based on the first element of A and update m
B[1] = A[1] - m
m = min(m, A[1])

# Loop through the remaining elements of A to fill B and update m
for i in range(2, N):
    # Fill B[i] with the difference between A[i] and the minimum value found so far (m)
    B[i] = A[i] - m

    # Update m to be the minimum of the current m and A[i]
    m = min(m, A[i])

# Count and output the number of times the maximum element in B appears
print(B.count(max(B)))

