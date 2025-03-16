
def solve(i, m):
    # Base case: if index exceeds the number of elements
    if i > n:
        return False
    # Base case: if the remaining sum is negative
    elif m < 0:
        return False
    # Base case: if the remaining sum is zero (solution found)
    elif m == 0 or m - A[i + 1] == 0:
        global flag
        flag = True  # Set flag to True indicating a solution is found
        return True  # Return True
    else:
        # Recursive case: do not use the current element A[i]
        solve(i + 1, m)
        # Recursive case: use the current element A[i]
        solve(i + 1, m - A[i])

# Read the number of elements in the array
n = int(input())
# Read the elements into the array A
A = [int(input()) for _ in range(n)]

# Read the number of queries
q = int(input())
# Process each query
for _ in range(q):
    # Read the target sum for the current query
    m = int(input())
    flag = False  # Reset flag for each query

    # Call the solve function to check if a subset sums to M
    solve(-1, m)
    # Output the result based on the flag
    if flag:
        print("yes")
    else:
        print("no")

