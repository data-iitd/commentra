

# Create a new Scanner object to read input from the console
import sys

# Read the number of test cases from the input
t = int(input())

# Iterate through each test case
for i in range(t):
    n = int(input()) # Read the number of elements in the array

    # Print the maximum left sum
    print(maxLeft(n))

# Function to calculate the maximum sum of elements to the left of a given index
def maxLeft(n):
    # Return the maximum left sum, which is the sum of elements from index 0 to the given index - 2
    return n - 2 if n > 2 else 0

# Close the Scanner object to free up system resources
sys.stdin.close()

