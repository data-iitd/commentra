
import sys

# Initialize scanner to read input from the standard input
sc = sys.stdin

# Read the first two integers from the standard input
N = int(sc.readline()) # Read the number of elements in the array
K = int(sc.readline()) # Read the size of the sliding window

# Allocate an integer array of size N to store the input elements
S = [0] * N

# Read the remaining elements of the array from the standard input
for i in range(N):
    S[i] = int(sc.readline()) # Read the next integer and store it in the array

# Initialize variables for calculating the answer
temp = 0
ans = 1000000000

# Check the special case when the size of the sliding window is 1
if K == 1:
    # Iterate through the array to find the minimum absolute value
    for i in range(N):
        temp = S[i] # Read the current element
        ans = min(abs(temp), ans) # Update the answer if necessary

    # Print the answer
    print(ans)
elif N - K!= 0: # Check the case when the size of the sliding window is not equal to the size of the array
    # Initialize variables for calculating the minimum and maximum elements in the sliding window
    min = 0
    max = 0

    # Iterate through all possible positions of the sliding window
    for i in range(N - K + 1):
        # Find the minimum and maximum elements in the current sliding window
        min = S[i]
        max = S[i + K - 1]

        # Calculate the sum of the absolute values of the minimum and maximum elements
        # and update the answer if necessary
        if min < 0 and max > 0:
            temp = 2 * (abs(min)) + max
        else:
            temp = max(abs(min), abs(max))
        ans = min(ans, temp)

    # Print the answer
    print(ans)
else: # Check the case when the size of the sliding window is equal to the size of the array
    # Find the minimum and maximum elements in the array
    min = S[0]
    max = S[N - 1]

    # Calculate the sum of the absolute values of the minimum and maximum elements
    # and print the answer directly
    if min < 0 and max > 0:
        print(min(2 * (abs(min)) + max, (abs(min)) + 2 * max))
    else:
        print(max(abs(min), abs(max)))

# Close the scanner to release the system resources
sc.close()

# 