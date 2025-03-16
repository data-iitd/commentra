# Declare variables for the number of elements (N) and a threshold (T)
N, T = map(int, input().split())

# Initialize an array A to hold the input values
A = [0] * N

# Read N integers into the array A
for i in range(N):
    A[i] = int(input())

# Initialize m with the first element of A
m = A[0]

# Initialize a vector B to hold the transformed values
B = [0] * N

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

