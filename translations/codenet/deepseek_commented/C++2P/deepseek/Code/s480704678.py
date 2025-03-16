import sys

# Read the size of the array
n = int(sys.stdin.readline().strip())

# Initialize the array and the cumulative sum array
a = list(map(int, sys.stdin.readline().strip().split()))
acc = [0] * (n + 1)

# Compute the cumulative sum
for i in range(n):
    acc[i + 1] = acc[i] + a[i]
    acc[i + 1] %= 1000000007

# Compute the answer
ans = 0
for i in range(n):
    ans += a[i] % 1000000007 * (1000000007 + acc[n] - acc[i + 1]) % 1000000007
    ans %= 1000000007

# Output the result
print(ans)
