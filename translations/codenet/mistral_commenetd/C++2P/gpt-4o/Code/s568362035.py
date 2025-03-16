MAXN = int(1E5 + 10)  # Maximum size of the input

# n: number of elements in the array, m: size of the result array, Q: number of queries
n, m, Q = map(int, input().split())
a = list(map(int, input().split()))  # Read queries

# Initialize variables
b = [0] * MAXN  # Output array
id = [0] * MAXN  # Index array
vis = [False] * MAXN  # Visited flag array
cnt = [0] * MAXN  # Counter array

# Find unvisited elements and add them to the output array
k = 0
for j in range(Q, 0, -1):
    if not vis[a[j - 1]]:
        k += 1
        b[k] = a[j - 1]  # Add the element to the output array
        vis[a[j - 1]] = True  # Mark it as visited

# Fill the output array with the remaining unvisited elements
j = m
for i in range(m, 0, -1):
    if not vis[i]:
        b[j] = i  # Add the element to the output array
        j -= 1

# Assign indices to the output array elements
for i in range(1, m + 1):
    id[b[i]] = i  # Assign index i to the element b[i]

# Process queries
flag = True
cnt[0] = n  # Initialize counter array with the number of elements in the input array
for i in range(Q, 0, -1):
    t = id[a[i - 1]]  # Get the index of the element a[i] in the output array
    if cnt[t - 1] > 0:  # If the previous element is still present in the input array
        cnt[t - 1] -= 1  # Decrease its counter
        cnt[t] += 1  # Increase the counter of the current element
        vis[t] = True  # Mark it as visited
    elif not vis[t]:  # If the current element is not present in the input array
        flag = False  # Set the flag to false and break the loop
        break

# Check the result
l = 0
while cnt[l] == 0:  # Find the last element that was present in the input array
    l += 1
for i in range(l + 1, m):
    flag &= b[i] < b[i + 1]  # Check if the output array is sorted in ascending order after the last present element

# Print the result
print("Yes" if flag else "No")
# <END-OF-CODE>
