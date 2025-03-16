
# Define types and macros for convenience
from collections import defaultdict

mod = 1000000007

# Input: Read the values of N and K
N,K = map(int,input().split())
A = list(map(int,input().split()))

# Solution: Calculate the number of inversions in the array
ans1 = 0
for i in range(N):
    for j in range(N):
        if i>=j: continue
        if A[i]>A[j]: ans1 += 1
        ans1 %= mod

# Count occurrences of each element in the array
count = defaultdict(int)
for i in A: count[i] += 1

# Calculate the second part of the answer based on the counts
ans2 = 0
remain = N
for i in range(2005):
    remain -= count[i]
    ans2 += count[i]*remain
    ans2 %= mod

# Calculate the final answer based on ans1 and ans2
ans = 0
tmp = K*(K-1)
tmp //= 2
tmp %= mod
tmp *= ans2
tmp %= mod
ans += ans1 * K
ans %= mod
ans += tmp
ans %= mod

# Output: Print the final answer
print(ans)

