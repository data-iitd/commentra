def check(lis, k, mid):
    # Initialize a loop to iterate through each element in the list
    for i in lis:
        # If the current element is divisible by mid, increment k
        if (i % mid == 0):
            k += 1
        # Decrease k by the number of times mid fits into the current element
        k -= (i // mid)
    # Return True if k is non-negative, indicating the condition is satisfied
    return k >= 0

# Read input values for n (number of elements) and k (threshold value)
n, k = map(int, input().split())
# Read the list of integers
lis = list(map(int, input().split()))

# Initialize the binary search bounds
a, b = 1, max(lis)
# Set the initial answer to the maximum value in the list
ans = b

# Perform binary search to find the optimal mid value
while (a <= b):
    # Calculate the mid value
    mid = (a + b) // 2
    # Check if the current mid value satisfies the condition using the check function
    if (check(lis, k, mid)):
        # If it does, update the answer and narrow the search to the left half
        ans = mid
        b = mid - 1
    else:
        # If it doesn't, narrow the search to the right half
        a = mid + 1

# Print the final answer
print(ans)
