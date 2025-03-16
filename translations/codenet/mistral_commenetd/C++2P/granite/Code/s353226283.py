

# Read input values for n and k
n, k = map(int, input().split())

# Initialize list'vec' with input values
vec = list(map(int, input().split()))

# Sort the list'vec' in ascending order
vec.sort()

# Initialize variable 'ans' with a large value
ans = 1000000001

# Iterate through the list with a sliding window of size 'k'
for i in range(n - k + 1):
    # Calculate the difference between the last and first element of the current window
    diff = vec[i+k-1] - vec[i]

    # Update the answer if the current difference is smaller than the previous one
    if diff < ans:
        ans = diff

# Print the answer
print(ans)

