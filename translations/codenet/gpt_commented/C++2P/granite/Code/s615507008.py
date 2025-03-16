
import sys

# Function to solve the problem based on the given parameters
def solve(N, T, M, P, X):
    for i in range(M):
        ans = 0 # Initialize the answer for the current modification
        for j in range(N):
            # If the current index matches the modified position, add the new time value
            if j == P[i] - 1: ans += X[i]
            # Otherwise, add the original time value
            else: ans += T[j]
        # Output the result for the current modification
        print(ans)

# Read input from the command line
N = int(input()) # Number of original time values
T = list(map(int, input().split())) # List to store the original time values
M = int(input()) # Number of modifications
P = [] # List to store the positions of modifications
X = [] # List to store the new time values for modifications
for _ in range(M):
    p, x = map(int, input().split())
    P.append(p)
    X.append(x)

# Call the solve function to process the modifications and output results
solve(N, T, M, P, X)

Translate the above Python code to Java and end with comment "