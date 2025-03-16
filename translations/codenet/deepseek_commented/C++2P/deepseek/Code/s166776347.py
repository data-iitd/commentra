import sys

# Read input
N, K = map(int, input().split())
A = list(map(int, input().split()))

# Solution
ans1 = 0
for i in range(N):
    for j in range(N):
        if i >= j:
            continue  # Skip if i is not less than j
        if A[i] > A[j]:
            ans1 += 1  # Increment ans1 if A[i] > A[j]
            ans1 %= 10**9 + 7  # Take modulo to prevent overflow

# Count the frequency of each element in the array A
count = [0] * 2005
for i in range(N):
    count[A[i] - 1] += 1  # Store frequency of A[i]

ans2 = 0
remain = N
for i in range(2005):
    remain -= count[i]  # Reduce the remaining count
    ans2 += count[i] * remain  # Calculate the number of valid pairs

# Calculate the final answer
tmp = K * (K - 1) // 2
tmp %= 10**9 + 7  # Take modulo to prevent overflow
tmp *= ans2
tmp %= 10**9 + 7  # Take modulo to prevent overflow
ans = 0
ans += ans1 * K  # Add contribution from ans1
ans %= 10**9 + 7  # Take modulo to prevent overflow
ans += tmp
ans %= 10**9 + 7  # Take modulo to prevent overflow

# Output the final answer
print(ans)
