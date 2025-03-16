
# Define the size of the count array
SIZE = (1e5 * 2) + 13

# Vector to store non-zero counts
a = []

# Vector to count occurrences of each integer
cnt = [0] * SIZE

# Read the number of elements and the threshold k
n, k = map(int, input().split())

# Count occurrences of each integer
for i in range(n):
    x = int(input())
    cnt[x] += 1

# Filter non-zero counts and store them in vector a
for i in range(SIZE):
    if cnt[i] > 0:
        a.append(cnt[i])

# Sort the vector a in ascending order
a.sort()

# Calculate the sum of the smallest k counts in vector a
ans = 0
m = len(a) - k
for i in range(m):
    ans += a[i]

# Output the result
print(ans)

