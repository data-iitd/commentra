# Function to solve the problem
def solve(N, T, M, P, X):
    # Initialize a variable to store the answer for each query
    ans = 0

    # Iterate through each query
    for i in range(M):
        # Initialize the answer variable to zero
        ans = 0

        # Iterate through each element in T up to the position of the current query
        for j in range(N):
            # If the current index j is equal to the position of the current query - 1
            if j == P[i] - 1:
                # Add the value of X[i] to the answer variable
                ans += X[i]
            # Otherwise, add the value of the current element in T to the answer variable
            else:
                ans += T[j]

        # Print the answer for the current query
        print(ans)

# Main function
if __name__ == "__main__":
    # Read the number of elements in T from the standard input
    N = int(input())

    # Initialize a vector T of size N
    T = [0] * N

    # Read the elements of T from the standard input
    for i in range(N):
        T[i] = int(input())

    # Read the number of queries from the standard input
    M = int(input())

    # Initialize vectors P and X of size M
    P = [0] * M
    X = [0] * M

    # Read the positions and values of the queries from the standard input
    for i in range(M):
        P[i], X[i] = map(int, input().split())

    # Call the solve function with the given arguments
    solve(N, T, M, P, X)

