# Define constants
LEN = 300
TRUE = 1
FALSE = -1

# Global variables
n = 0  # Number of elements
A = [0] * LEN  # Array of elements
flag = FALSE  # Flag to indicate if a solution is found

def solve(i, m):
    global flag
    # Base case: if index exceeds the number of elements
    if i >= n:
        return FALSE
    # Base case: if the remaining sum is negative
    elif m < 0:
        return FALSE
    # Base case: if the remaining sum is zero (solution found)
    elif m == 0 or m - A[i + 1] == 0:
        flag = TRUE  # Set flag to TRUE indicating a solution is found
        return TRUE  # Return TRUE
    else:
        # Recursive case: do not use the current element A[i]
        solve(i + 1, m)
        # Recursive case: use the current element A[i]
        solve(i + 1, m - A[i])

# Main function
if __name__ == "__main__":
    global n, A, flag
    q = int(input())  # Read the number of queries

    # Read the number of elements in the array
    n = int(input())
    # Read the elements into the array A
    A = list(map(int, input().split()))

    # Process each query
    for _ in range(q):
        M = int(input())  # Read the target sum for the current query
        flag = FALSE  # Reset flag for each query

        # Call the solve function to check if a subset sums to M
        solve(-1, M)
        # Output the result based on the flag
        if flag == TRUE:
            print("yes")
        else:
            print("no")

# <END-OF-CODE>
