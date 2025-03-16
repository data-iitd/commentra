# Read the number of elements in the array
n = int(input())

# Read the array elements from input, converting them to integers
arr = list(map(int, input().strip().split()))[:n]

# Initialize an answer array with zeros, which will store the results
ans = [0] * n

# Set the maximum value to the last element of the array
mx = arr[-1]

# Iterate through the array from the second last element to the first
for i in range(n - 2, -1, -1):
    # Calculate the required value for ans[i] based on the difference from the maximum
    ans[i] = max(0, mx - arr[i] + 1)
    
    # Update the maximum value if the current element is greater than the current maximum
    if arr[i] > mx:
        mx = arr[i]

# Print the result array as space-separated values
print(*ans)
