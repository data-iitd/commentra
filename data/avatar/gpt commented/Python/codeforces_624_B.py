import sys

# Use readline for faster input
input = sys.stdin.readline

# Read the number of elements
n = int(input())

# Read the list of integers and convert them to a list of integers
a = list(map(int, input().split()))

# Initialize the previous value to infinity
pre = float('inf')

# Initialize the answer variable to accumulate the result
ans = 0

# Sort the list in descending order
a.sort(reverse=True)

# Iterate through the sorted list
for j in range(n):
    # Calculate the current contribution to the answer
    # It takes the minimum of (pre - 1) and the current element a[j], ensuring it's non-negative
    ans += max(0, min(pre - 1, a[j]))
    
    # Update the previous value for the next iteration
    pre = max(0, min(pre - 1, a[j]))

# Print the final accumulated answer
print(ans)
