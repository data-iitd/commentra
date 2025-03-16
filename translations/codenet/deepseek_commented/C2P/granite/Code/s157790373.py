
# Python code

# Function to solve the subset sum problem
def solve(A, M):
    # Base case: if the array A is empty, return False
    if len(A) == 0:
        return False
    # If the remaining sum M is negative, return False
    elif M < 0:
        return False
    # If the remaining sum M is zero, return True
    elif M == 0:
        return True
    else:
        # Recursive call without using the current element A[0]
        if solve(A[1:], M):
            return True
        # Recursive call using the current element A[0]
        if solve(A[1:], M - A[0]):
            return True
    # If none of the recursive calls return True, return False
    return False

# Read the number of elements in the array
n = int(input())
# Read the elements of the array
A = list(map(int, input().split()))

# Read the number of queries
q = int(input())
# Iterate over each query
for i in range(q):
    # Read the target sum for the current query
    M = int(input())
    # Call the solve function to find a subset that sums up to M
    if solve(A, M):
        print("yes")
    else:
        print("no")

