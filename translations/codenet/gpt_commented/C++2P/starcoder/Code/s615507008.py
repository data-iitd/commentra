# Function to solve the problem based on the given parameters
def solve(N, T, M, P, X):
    # Iterate over each modification request
    for i in range(M):
        ans = 0 # Initialize the answer for the current modification
        # Calculate the total time considering the current modification
        for j in range(N):
            # If the current index matches the modified position, add the new time value
            if j == P[i] - 1: ans += X[i]
            # Otherwise, add the original time value
            else: ans += T[j]
        # Output the result for the current modification
        print(ans)

if __name__ == "__main__":
    # Untie cin from cout for faster input
    import sys
    sys.stdin = open("input.txt", "r")
    sys.stdout = open("output.txt", "w")

    N = int(input()) # Number of original time values
    T = [int(input()) for i in range(N)] # Vector to store the original time values
    M = int(input()) # Number of modifications
    P = [int(input()) for i in range(M)] # Vector to store the positions of modifications
    X = [int(input()) for i in range(M)] # Vector to store the new time values for modifications

    # Call the solve function to process the modifications and output results
    solve(N, T, M, P, X)
    print("