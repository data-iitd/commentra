
# Define input variables
n, k = map(int, input().split())

# Initialize vector'vec' with size 'n'
vec = []
for i in range(n):
    # Read input value for 't' and add it to the vector
    t = int(input())
    vec.append(t)

# Sort the vector'vec' in ascending order
vec.sort()

# Iterate through the vector with a sliding window of size 'k'
for i in range(n - k + 1):
    # Calculate the difference between the last and first element of the current window
    diff = vec[i+k-1] - vec[i]

    # Update the answer if the current difference is smaller than the previous one
    if diff < ans:
        ans = diff

# Print the answer
print(ans)

