import sys

# Function to solve the problem based on the given parameters
def solve(N, T, M, P, X):
    # Iterate over each modification request
    for i in range(M):
        ans = 0  # Initialize the answer for the current modification
        # Calculate the total time considering the current modification
        for j in range(N):
            # If the current index matches the modified position, add the new time value
            if j == P[i] - 1:
                ans += X[i]
            # Otherwise, add the original time value
            else:
                ans += T[j]
        # Output the result for the current modification
        print(ans)

# Read input from stdin
def main():
    input = sys.stdin.readline
    # Read the number of original time values
    N = int(input())
    # Read the original time values into a list
    T = list(map(int, input().split()))

    # Read the number of modifications
    M = int(input())
    # Initialize lists to store the positions and new time values for modifications
    P = [0] * M
    X = [0] * M
    # Read the modification positions and new time values
    for i in range(M):
        P[i], X[i] = map(int, input().split())

    # Call the solve function to process the modifications and output results
    solve(N, T, M, P, X)

# Call the main function to execute the program
if __name__ == "__main__":
    main()
