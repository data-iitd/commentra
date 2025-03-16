
# Define a shorthand for repetition
def rep(i, n):
    for i in range(n):

# Read the number of elements in the vector
N = int(input())

# Initialize a vector of size N with integers
A = [int(input()) for i in range(N)]

# Initialize the answer variable to 0
answer = 0

# Outer loop iterates through each element in the vector except the last one
for i in range(N - 1):
    # Inner loop iterates through the remaining elements in the vector starting from the next element
    for j in range(i + 1, N):
        # Calculate the absolute difference between the current and next elements
        diff = abs(A[i] - A[j])

        # Update the answer variable with the maximum difference found so far
        answer = max(answer, diff)

# Print the answer
print(answer)

