

n = int(input()) # Read the number of elements
N = 100005 # Define a constant N for array size
cnt = [0] * (2 * N) # Initialize an array to count occurrences of each value shifted by N

# Count the occurrences of each value shifted by N
for i in range(n):
    cnt[int(input()) + N] += 1

res = 0 # Initialize result variable

# Calculate the number of pairs that sum up to 2 * N
for i in range(N):
    res += cnt[i] * cnt[2 * N - i]

# Special case for pairs where both elements are the same (i.e., i = N)
res += (cnt[N] * (cnt[N] - 1)) // 2

# Output the result
print(res)

