
import sys

# Read the number of test cases from the input
t = int(sys.stdin.readline().strip())

# Iterate through each test case
for i in range(t):
    # Read the number of elements in the array
    n = int(sys.stdin.readline().strip())

    # Print the maximum left sum
    print(maxLeft(n))

# Function to calculate the maximum sum of elements to the left of a given index
def maxLeft(n):
    # Return the maximum left sum, which is the sum of elements from index 0 to the given index - 2
    return n - 2 if n > 2 else 0

# END-OF-CODE
