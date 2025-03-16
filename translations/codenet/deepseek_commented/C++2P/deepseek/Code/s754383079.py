import sys

# Read input strings
a = ' ' + sys.stdin.readline().strip()
n = len(a) - 1
b = ' ' + sys.stdin.readline().strip()
m = len(b) - 1

# Calculate the minimum number of differences
ans = n + 10
for i in range(1, n - m + 2):
    sum = 0
    for j in range(1, m + 1):
        if a[i + j - 1] != b[j]:
            sum += 1
    ans = min(ans, sum)

# Output the result
print(ans)
