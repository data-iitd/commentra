
# Read the number of elements (n) and the size of the subset (k)
n, k = map(int, input().split())

# Read n integers from input and store them in the list
vec = list(map(int, input().split()))

# Sort the list in non-decreasing order
vec.sort()

# Initialize ans to a large value to find the minimum difference
ans = 1000000001

# Iterate through the sorted list to find the minimum difference
for i in range(n - k + 1):
    # Calculate the difference between the maximum and minimum of the current subset of size k
    diff = vec[i + k - 1] - vec[i]
    
    # Update the minimum difference found so far
    if diff < ans:
        ans = diff # Update ans if a smaller difference is found

# Output the minimum difference found
print(ans)

