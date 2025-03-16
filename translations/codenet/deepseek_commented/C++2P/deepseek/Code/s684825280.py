SIZE = (10**5 * 2) + 13

# Initialize the count array and the non-zero counts vector
cnt = [0] * SIZE
a = []

# Read the number of elements and the threshold k
n, k = map(int, input().split())

# Count occurrences of each integer
for _ in range(n):
    x = int(input())
    cnt[x] += 1

# Filter non-zero counts and store them in vector a
for i in range(SIZE):
    if cnt[i] > 0:
        a.append(cnt[i])

# Sort the vector a in ascending order
a.sort()

# Calculate the sum of the smallest k counts in vector a
ans = sum(a[:len(a) - k])

# Output the result
print(ans)
