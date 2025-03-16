
# Read the size of the arrays from user input
N = int(input())

# Declare an array A of size N+1 and an array B of size N
A = [int(x) for x in input().split()]
B = [int(x) for x in input().split()]

# Initialize a variable to hold the total answer
ans = 0

# Loop through each index of the arrays to calculate the answer
for i in range(N):
    # Handle the case for site i
    if A[i] >= B[i]:
        # If A[i] can satisfy B[i], add B[i] to the answer
        ans += B[i]
        # Decrease A[i] by B[i] and set B[i] to 0
        A[i] -= B[i]
        B[i] = 0
    else:
        # If A[i] cannot satisfy B[i], add A[i] to the answer
        ans += A[i]
        # Decrease B[i] by A[i] and set A[i] to 0
        B[i] -= A[i]
        A[i] = 0

    # Handle the case for site i + 1
    if A[i + 1] >= B[i]:
        # If A[i + 1] can satisfy B[i], add B[i] to the answer
        ans += B[i]
        # Decrease A[i + 1] by B[i] and set B[i] to 0
        A[i + 1] -= B[i]
        B[i] = 0
    else:
        # If A[i + 1] cannot satisfy B[i], add A[i + 1] to the answer
        ans += A[i + 1]
        # Decrease B[i] by A[i + 1] and set A[i + 1] to 0
        B[i] -= A[i + 1]
        A[i + 1] = 0

# Print the final answer
print(ans)

