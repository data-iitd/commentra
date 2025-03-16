
# Define the size of the vector
SIZE = (1e5 * 2) + 13

# Initialize an empty vector 'a' to store the frequency count of each element
a = []

# Initialize a vector 'cnt' of size 'SIZE' to store the frequency count of each element
cnt = [0] * SIZE

# Read the number of elements 'n' and the number of frequencies to consider 'k' from the standard input
n, k = map(int, input().split())

# Loop through the input elements
for i in range(n):
    # Read an element 'x' from the standard input
    x = int(input())

    # Increment the frequency count of the element 'x' in the vector 'cnt'
    cnt[x] += 1

# Loop through all elements in the vector 'cnt'
for i in range(SIZE):
    # If the frequency count of an element is greater than zero
    if cnt[i] > 0:
        # Add the frequency count to the vector 'a'
        a.append(cnt[i])

# Initialize an integer 'ans' to store the sum of the first 'k' frequency counts
ans = 0

# Sort the vector 'a' in ascending order
a.sort()

# Calculate the index of the last frequency count to be considered
m = len(a) - k

# Loop through the first 'k' frequency counts and add them to the variable 'ans'
for i in range(m):
    ans += a[i]

# Print the result 'ans' to the standard output
print(ans)

# 