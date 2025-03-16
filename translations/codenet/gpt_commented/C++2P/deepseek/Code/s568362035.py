MAXN = 100010  # Define a constant for the maximum size of arrays

# Declare variables for number of elements, maximum value, and number of queries
n, m, Q = 0, 0, 0
# Declare arrays to store the queries, unique values, and their indices
a = [0] * MAXN
b = [0] * MAXN
id = [0] * MAXN
vis = [False] * MAXN
cnt = [0] * MAXN

# Read the number of elements (n) and the maximum value (m)
n, m = map(int, input().split())
# Read the number of queries (Q)
Q = int(input())

# Read the queries into array a
a[1:Q+1] = map(int, input().split())

# Process the queries to fill array b with unique values from a
k = 0
for j in range(Q, 0, -1):
    if not vis[a[j]]:
        k += 1
        b[k] = a[j]
        vis[a[j]] = True

# Fill the remaining positions in b with the largest unused values up to m
for j in range(m, 0, -1):
    if not vis[j]:
        k += 1
        b[k] = j

# Map each value in b to its index in id
for i in range(1, m + 1):
    id[b[i]] = i

flag = True  # Initialize a flag to track the validity of the sequence
cnt[0] = n  # Initialize the count of the first value to n

# Process the queries in reverse order
for i in range(Q, 0, -1):
    t = id[a[i]]  # Get the index of the current query value
    if cnt[t - 1] > 0:  # If there are available counts for the previous index
        cnt[t - 1] -= 1  # Decrease the count for the previous index
        cnt[t] += 1  # Increase the count for the current index
        vis[t] = True  # Mark the current index as seen
    elif not vis[t]:  # If the current index has not been seen
        flag = False  # Set the flag to false, indicating an invalid sequence
        break  # Exit the loop

# Find the first index l where count is non-zero
l = 0
while cnt[l] == 0:
    l += 1

# Check if the remaining values in b are in increasing order
for i in range(l + 1, m):
    if b[i] >= b[i + 1]:
        flag = False
        break

# Output the result based on the flag
print("Yes" if flag else "No")
