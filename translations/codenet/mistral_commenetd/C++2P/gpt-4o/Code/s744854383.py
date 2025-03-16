# Import necessary libraries
import sys

# Define constants
INF = int(2e9)  # Constant for infinity
M_PI = 3.14159265358979323846  # Constant for pi

# Read the number of elements from the standard input
N = int(input())

# Allocate memory for the array and read its elements
a = list(map(int, input().split()))

# Initialize variables
idx = 1  # Index for checking the current element in the array
ans = 0  # Variable to store the answer

# Process the array
for i in range(N):
    # Check if the current element matches the index
    if a[i] == idx:
        # Increment the index
        idx += 1
    else:
        # Increment the answer
        ans += 1

# Output the result
if idx == 1:
    print(-1)  # Output -1 if all elements are the same
else:
    print(ans)  # Output the answer otherwise

# Terminate the program
# <END-OF-CODE>
