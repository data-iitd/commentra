# Define input variables
n, k = map(int, input().split())
vec = []
ans = 1000000001

# Initialize vector 'vec' with input values
for _ in range(n):
    t = int(input())
    vec.append(t)

# Sort the vector 'vec' in ascending order
vec.sort()

# Iterate through the vector with a sliding window of size 'k'
for i in range(n - k + 1):
    # Calculate the difference between the last and first element of the current window
    diff = vec[i + k - 1] - vec[i]

    # Update the answer if the current difference is smaller than the previous one
    if diff < ans:
        ans = diff

# Print the answer
print(ans)

# <END-OF-CODE>
