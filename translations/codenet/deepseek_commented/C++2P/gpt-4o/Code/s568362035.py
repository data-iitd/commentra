MAXN = int(1E5 + 10)  # Define the maximum size for arrays

n, m, Q = map(int, input().split())  # Read the size of array a and the number of positions m
a = list(map(int, input().split()))  # Read the elements of array a

b = [0] * MAXN  # Declare array b to store unique elements
id = [0] * MAXN  # Declare array id for storing positions
vis = [False] * MAXN  # Declare a boolean array vis to mark processed elements
cnt = [0] * MAXN  # Declare an array cnt to count elements in each position

# Process the elements of array a
k = 0
for j in range(Q, 0, -1):
    if not vis[a[j - 1]]:
        k += 1
        b[k] = a[j - 1]
        vis[a[j - 1]] = True

# Fill the remaining positions in b
j = k
for i in range(m, 0, -1):
    if not vis[i]:
        j -= 1
        b[j] = i

# Store the position of each element in b
for i in range(1, m + 1):
    id[b[i]] = i

flag = True  # Initialize flag to true
cnt[0] = n  # Initialize the count of elements in the first position

# Iterate through the elements of array a in reverse order
for i in range(Q, 0, -1):
    t = id[a[i - 1]]  # Get the position of the current element in b
    if cnt[t - 1] > 0:  # If there is a position available one less than the current position
        cnt[t - 1] -= 1  # Decrease the count of the previous position
        cnt[t] += 1  # Increase the count of the current position
        vis[t] = True  # Mark the current position as processed
    elif not vis[t]:  # If the current position is not available and not yet marked as processed
        flag = False  # Set flag to false
        break  # Break out of the loop

# Find the smallest index l with a non-zero count
l = 0
while cnt[l] == 0:
    l += 1

# Check if the elements in b are in strictly increasing order
for i in range(l + 1, m):
    flag &= b[i] < b[i + 1]

print("Yes" if flag else "No")  # Print "Yes" if the conditions are met, otherwise print "No"
# <END-OF-CODE>
